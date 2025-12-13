//some mecanum steering code inspired by Gavin Ford (on Youtube) + many many edits by me
//this code is for an arduino board that will be used to control the steering of a mecanum wheel robot
//this code will read in data Serial port connected to a Raspberry Pi that will send in the speed and direction data for the robot to follow

#include <math.h> // include to use sine and cosine for calculating vector trajectory

//===================
// global variables used in the various functions

const byte buffSize = 32;
char inputSeveral[buffSize]; // space for 31 chars and a terminator

float inputSpeed = 0.0;
float inputDirec = 0.0;

// intialize forward drive pins
int pwr_Rfnt = 13; // ENA "power to tbe Right, Front wheel"
int fwd_Rfnt = 12; // IN1 "right, front wheel drives forward"
int bwd_Rfnt = 11; // IN2 "right, front wheel drives backward"
int fwd_Lfnt = 10; // IN3 "left, front wheel drives forward"
int bwd_Lfnt = 9; // IN4 "left, front wheel drives backward"
int pwr_Lfnt = 8; //ENB "power to tbe left, Front wheel"

// intialize rear drive pins
int pwr_Rbck = 7; //ENA
int fwd_Rbck = 6; //IN1
int bwd_Rbck = 5; // IN2
int fwd_Lbck = 4; // IN3
int bwd_Lbck = 3; //IN4
int pwr_Lbck = 2; //ENB

//initialize vector
double current_power = 0;  // starting power (e.g., 0)
double target_power = 225; // desired power

double target_theta_deg=0; //will be inputted by fish, degrees
double target_theta_rad=0;
double current_theta_rad=0;  
double mx=0;
double interp_speed = 0.1; // how fast you want the power to change
int incomingByte = 0;

void setup() {
//include serial monitor for debugging (remove later bc it makes it wayyyy slower)
  Serial.begin (9600); 

//intialize motor power pins
  pinMode(pwr_Rfnt, OUTPUT);
  pinMode(pwr_Lfnt, OUTPUT);
  pinMode(pwr_Rbck, OUTPUT);
  pinMode(pwr_Lbck, OUTPUT);

//intialize motor direction pins
  pinMode(fwd_Rfnt, OUTPUT);
  pinMode(bwd_Rfnt, OUTPUT);
  pinMode(fwd_Lfnt, OUTPUT);
  pinMode(bwd_Lfnt, OUTPUT);
  pinMode(fwd_Rbck, OUTPUT);
  pinMode(bwd_Rbck, OUTPUT);
  pinMode(fwd_Lbck, OUTPUT);
  pinMode(bwd_Lbck, OUTPUT);

//initialize motor direction to "off"
  digitalWrite(fwd_Rfnt, LOW);
  digitalWrite(bwd_Rfnt, LOW);
  digitalWrite(fwd_Lfnt, LOW);
  digitalWrite(bwd_Lfnt, LOW);

  digitalWrite(fwd_Rbck, LOW);
  digitalWrite(bwd_Rbck, LOW);
  digitalWrite(fwd_Lbck, LOW);
  digitalWrite(bwd_Lbck, LOW);
}

void loop() {

  readCSV();
//get a radian vector and power scalar
  //target_power = new_power();  // Update target power based on fish data or any other input
  // Interpolate between current power and target power
  current_power = lerp(current_power, target_power, interp_speed);

  //target_theta_deg=new_theta(); //currently pulls from a function (see below), in the future will pull from fish-vector data
  //target_theta_rad=target_theta_deg*(M_PI/180)+(M_PI/4);
  // Interpolate between current theta and target theta
  current_theta_rad = lerp(current_theta_rad, target_theta_rad, interp_speed);

  mx=max(abs(sin(current_theta_rad)), abs(cos(current_theta_rad)));

//set speed (power) and direction of each motor
  set_direc_pwr(pwr_Rfnt, fwd_Rfnt, bwd_Rfnt, current_power*sin(current_theta_rad)/mx);
  set_direc_pwr(pwr_Lfnt, fwd_Lfnt, bwd_Lfnt, current_power*cos(current_theta_rad)/mx);
  set_direc_pwr(pwr_Rbck, fwd_Rbck, bwd_Rbck, current_power*cos(current_theta_rad)/mx);
  set_direc_pwr(pwr_Lbck, fwd_Lbck, bwd_Lbck, current_power*sin(current_theta_rad)/mx);

  delay(100);
  
}

void set_direc_pwr (int pwr_mtr, int fwd_mtr, int bwd_mtr, double pwr_funct) {
  if (pwr_funct>0){ // set forwards
    digitalWrite(fwd_mtr, HIGH);  //fwd_mtr refers to fwd_Rfnt, fwd_Lbck, etc
    digitalWrite(bwd_mtr, LOW);   //bwd_mtr refers to bwd_Rfnt, bwd_Lfnt, etc
  } else { //OR set backwards
    digitalWrite(fwd_mtr, LOW);
    digitalWrite(bwd_mtr, HIGH);
  }

  //set power
  analogWrite(pwr_mtr, abs(pwr_funct)); //pwr_mtr refers to pwr_Rfnt, pwr_Lbck, etc; pwr_funct refers to sine/cosine function that gives 0-255 value for speed (power)
  
}

void stop (int time) {
  digitalWrite(fwd_Rfnt, LOW);
  digitalWrite(bwd_Rfnt, LOW);
  digitalWrite(fwd_Lfnt, LOW);
  digitalWrite(bwd_Lfnt, LOW);

  digitalWrite(fwd_Rbck, LOW);
  digitalWrite(bwd_Rbck, LOW);
  digitalWrite(fwd_Lbck, LOW);
  digitalWrite(bwd_Lbck, LOW);

  delay(time);
}

int new_theta(){
  //readCSV();
  //target_theta_deg=inputDirec;
  return target_theta_deg;
} 

int new_power(){
  //holds power constant; will eventually increase
  target_power=225;
  target_power = constrain(target_power, 0, 255);
  return target_power;
}

double lerp(double start, double end, double t) {
  return start + (end - start) * t;
}

void readCSV() {
// Wait until a full line is received
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n'); // Read entire line
    inputString.toCharArray(inputSeveral, buffSize); // Convert to char array for strtok()

    char *partOfString = strtok(inputSeveral, ",");
    if (partOfString != NULL) {
      inputSpeed = atof(partOfString);  // First CSV value
    }

    partOfString = strtok(NULL, ",");
    if (partOfString != NULL) {
      inputDirec = atof(partOfString);  // Second CSV value 
    }

//going to comment this out to stop the rasppi from reading it
    Serial.print("Speed: ");
    Serial.println(inputSpeed);
    Serial.print("Direction: ");
    Serial.println(inputDirec);
  }

  target_power = constrain(inputSpeed, 0, 255);
  target_theta_deg=inputDirec;
  target_theta_rad=target_theta_deg*(M_PI/180)+(M_PI/4);
}
