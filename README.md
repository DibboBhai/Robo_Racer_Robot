# Robo_Racer_Robot

Robo Race bot created by students of RoboTech Club at National Institute of Science Education and Research in an attempt for participating in competitions. The purpose of the project is to learn the use of transmitter and receiver and for wireless interactions. And the bot was made for participating the competitions organized in techfests.

# Time Line

- Start of Project - 4 January 2024
- Participation in NIRMAN 3rd Edition in Silicon Institute of Technology, Bhubaneswar - 19 February 2024

# Problem Statement

There will be a race track and the racing track will have many obstacles and elements of surprises. Each obstacle has a task and the bot is supposed to the task. If the bot performs the task full points will be given to bot for completing the obstacle or if the bot don't perform then no points will be given. The team is allowed to skip obstacles if they are unable to do but some points are deducted from the team as penalty and if the team toches the bot to keep it back in track then the team has to pay penalty of time. In this way 2 bots will compete with each other. Time taken by every bot will be noted. The bot which completes the track in least time wins the competition.

# Concept/Theory

The concept used for building the bot is that the receiver receives some values from the transmitter given by the user and the user has the control of the transmitter by using the joysticks and the buttons in the transmitter. The user gives input according to the action he wants the bot to perform. The receiver gives the input given by user to microprocessor and then the bot performs the task accordingly.

# Equipments Used

- Arduino UNO
- Breadboard, Jumper Wires, Switch(SPST)
- Li-ion battery 3S: ~12V
- LN 298N Motor Driver
- Acylic Used to make Chassis
- Johnson Motors ×4
- Motor Wheels ×4
- Hinge
- Nut and Blots for attaching Wheels
- Flysky FS-CT6B Transmitter
- Receiver
- Nuts & Blots, Glue gun, Soldering iron, Double Tapes and Tapes

# System Architecture

At the very starting we have put the 2 front motors of the bots. Arduino is setup in the front for ease in uploading of code. Nearly at the centre the battery is placed. After battery the breadboard is placed and it interacts with every component of the system for ground and for 5 V power supply. After breadboard the receiver and the Motor Driver are placed sideways. At the very end we have placed our 2 back motors of the bot.

# Mechanical Design

The 2D design is created in Onshape and then we used Laser cutter to get precise design in the Acrylic. We made the bot in shape of cuboid. The dimension of the cuboid was 170mm × 300mm × 70mm. At the top cover we put a hinge at the posterior part of the bot a small box cut at top for fitting switch. The design can be found in the link below.

[The Link for the 2D design](https://cad.onshape.com/documents/d5d891ddd6445b480410c69e/w/940477b93a4f2d0b305ebcb4/e/ea15fd9b8ccd93f9f53267da)

# Electrical Connections

| Battery and Motor Driver               | Motor Driver and Arduino      | Receiver and Arduino | Motor Driver and Motors     | Breadboard to rest of circuit                 |
| -------------------------------------- | ----------------------------- | -------------------- | --------------------------- | --------------------------------------------- |
|12V Positive of battery connected to 12V|5V common connected to Arduino | Channel 2 in Pin 3   | Left Motor Positive in OUT1 | 5V Positive of Motor Driver to Common Positive|
|                                        | ENA to Pin 5                  | Channel 3 in Pin 2   | Left Motor Negative in OUT2 | Ground of Battery to Common Ground            |
|                                        | IN1 to Pin 4                  |                      | Right Motor Negative in OUT3| Positive of Arduino to Common Positive        |
|                                        | IN2 to Pin 6                  |                      | Right Motor Positive in OUT4| Positive of Receiver to Common Positive       |
|                                        | ENB to Pin 9                  |                      |                             | Negative of Arduino to Common Negative        |
|                                        | IN3 to Pin 8                  |                      |                             | Negative of Receiver to Common Negative       |                         
|                                        | IN4 to Pin 10                 |                      |                             | Negative of Motor Driver to Common Negative   |

# Transmitter and Receiver Setup

In this project we are using Flysky FS-CT6B Transmitter. It is device used by Driver to control the Bot wirelessly. Transmitter takes input from user about what task to perform accordin to what the user has set up and the receiver recives the input given by user by Radiowaves sent by the transmitter. Then receiver decodes the waves and send the input values to the microprocessor then it takes decision of what output must be given according to te way it has been programmed. Every channels of receiver has a specific botton or joystick which it is connected to and every bottons and joystic independently send their signals. So  every channel receives different input. And with different inputs we can do multitasking and make the bot work.

In our case we will use only 2 channels. One channels will help in controling the forward left and forward right wheel and other channel will help in controlling the forward right and backward wheel.

- Left wheels (both backward and forward) control ---> channel 2
- Right wheels (both backward and forward) control ---> channel 3

![image](https://github.com/DibboBhai/Robo_Racer_Robot/assets/148962484/7474b158-252c-4d5a-ac55-f2d05743f883) <img src="https://github.com/DibboBhai/Robo_Racer_Robot/assets/148962484/799f5dda-c8e9-4137-bd46-c04fa60250c4" height = 300 width = 300>  <img src ="https://github.com/DibboBhai/Robo_Racer_Robot/assets/148962484/75919350-2e63-4e4d-bec7-76d75963875f" height=300 width=300> 

# Motor Driver Controlling

Whenever the driver wants to make a motion he can change the direction of wheels by changing the voltage supply of IN pins and can change the speed by varying the voltage supply to EN pins.

| FORWARD DIRECTION | BACKWARD DIRECTION | LEFT DIRECTION                            | RIGHT DIRECTION    |
| ----------------- | ------------------ | ---------------------------------------   | ------------------ |
| IN1 voltage HIGH  | IN1 voltage LOW    | IN1 voltage HIGH OR LOW (SAME AS IN2)     | IN1 voltage HIGH  |
| IN2 voltage LOW   | IN2 voltage HIGH   | IN2 voltage HIGH OR LOW (SAME AS IN1)     | IN2 voltage LOW   |
| IN3 voltage LOW   | IN3 voltage HIGH   | IN3 voltage LOW                           | IN3 voltage HIGH OR LOW (SAME AS IN4) |
| IN4 voltage HIGH  | IN4 voltage LOW    | IN4 voltage HIGH                          | IN4 voltage HIGH OR LOW (SAME AS IN3) |

Apart for controling we observe the magnitude of how much the joystick by mapping is given the arduino instruct the motor driver to how much power is to be give.

# 
