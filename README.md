# FISHMOBILE, A FISH OPERATED VEHCILE

**Real-Time Locomotion of an RC Car Controlled by a Live Fish via Computer Vision**

The Wright Brothers made history when they successfully took the first flight, making men not merely terrestrial creatures but also aerial creatures. Together with Phoebe Lin and Ria Mirchandani, we are attempting to make the same leap for our aquatic friends. No longer will fish be relegated to the sea but welcome on the land. Now presenting: THE FISHMOBILE, a fish-operated vehicle.

[Live Demo at Open Sauce](https://youtu.be/FGOOzoZ57nk) (ft. a robotic fish)

![Alt text](https://images.squarespace-cdn.com/content/v1/6639961be2f0855f8c34337c/511aca56-f49f-474a-af5a-4cdfc76c18de/IMG_3893.PNG?format=2500w)

---

## Table of Contents
- [Background](#background)  
- [Inspiration](#inspiration)  
- [Hardware Setup](#hardware-setup)  
- [Software Setup](#software-setup)
- [Serial Communication](#serial-communication)
- [Usage](#usage)  
- [Contributing](#contributing)  
- [License](#license)  

---

## Background
This project is an experimental robot that uses a Raspberry Pi 3 and an Arduino Mega to navigate with a Mecanum wheel chassis. Most critically, the speed and direction of the chassis is controlled by a fish swimming inside a tank onto of the chassis. The Raspberry Pi handles fish-tracking and vision processing using the Pi Camera and OpenCV, while the Arduino Mega controls the motors via the motor driver board.  

The main goals of the project are:  
- Autonomous movement based on camera input  
- Communication between Raspberry Pi and Arduino over serial  
- Exploration of Mecanum wheel kinematics
- Allow a fish to drive around land autonomously

We have been working on this project for over a year, presenting it at OpenSauce, TN Maker Fest, and at our university. 

- [Design Process Video!](https://youtu.be/sza0JBSlZPk?si=AvpnyFDG3D8n4rz9)
- [Press: "Best of OpenSauce"](https://www.hackster.io/news/the-best-of-open-sauce-2025-our-top-9-picks-0d1e72723245#toc--7---goldfish-can-drive-cars-now-2)
- [Live Demo at Open Sauce](https://youtu.be/FGOOzoZ57nk)

---

## Inspiration
This project was inspired by the research paper:  
*"From fish out of water to new insights on navigation mechanisms in animals"* by *Givon, Samina, Ben-Shahar, and Segev, 2021*  

Key takeaways from the paper:  
- Integration of vision-based control with microcontroller-driven motors  
- Use of serial communication for real-time control
- Integration of a fish tank for fish-controlled moton
- Use of mecanum wheels for 3 DOFS of movement (complete X, Y, Z, & roll)

---

## Hardware Setup
Components used:  
- **Raspberry Pi 3**  
  - Installed with **OpenCV** and **Picamera**  
- **Arduino Mega**  
- **Mecanum Chassis Kit** (with motor drivers)
  - I used this one: https://a.co/d/bvR9BbD (not an affliate link)
- **Raspberry Pi Camera Module**  
- **Power supply** (rechargable LiPo battery)  

**Connections:**  
- Arduino Mega connected to Raspberry Pi via USB for serial communication  
- Motor drivers connected to Arduino Mega  
- Camera module connected to Raspberry Pi  

---

## Software Setup
### Raspberry Pi
1. Update and install dependencies:  
```bash
sudo apt update
sudo apt install python3-opencv python3-picamera python3-pip
pip3 install pyserial
```
2. Download [fish_tracking_cv](fish_tracking_cv) to your RaspPi


### Arduino
1. Open [fishmobile_src_with_PC_teleop.ino](fishmobile_src_with_PC_teleop.ino) in the Arduino IDE
2. Set board to MEGA
3. Compile and upload

---
## Serial Communication
- Raspberry Pi sends motor speed and direction commands to Arduino over USB serial
- Troubleshooting tips:
  - Ensure the correct serial port is selected on the Pi
  - Baud rate must match between Pi and Arduino
 
---
## Usage
1. Ensure connections
  - RaspPi and Arduino serial connection
  - Battery to Arduino & motor drivers
2.  Ensure files are downloaded:
  - Open [fish_tracking_cv](fish_tracking_cv) on RaspPi desktop / Remote Desktop
   - Terminal is not recommended
  - Load [fishmobile_src_with_PC_teleop.ino](fishmobile_src_with_PC_teleop.ino) onto the Arduino mega
3. Run [fish_tracking_cv](fish_tracking_cv)

---
## Contributing
Contributions are welcome! 
- I'm certainly not the first person to do this project and hope I am not the last.
- Open an issue for bugs or feature requests
- Submit a pull request for improvements
- Please follow proper coding standards and provide documentation for changes

---
## License
This project is licensed under the **MIT License** See [License](LICENSE)
