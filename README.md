# Obstacle Avoiding Robot
This robot avoids obstacles in front of it by scanning left and right and repeating the process. I built it to understand how a self-moving robot operates.

# Components Used

- 18cm*10cm carboard
- 3 wheels 3cm radius
- 5 rubber bands
- stick
- Breadboard
- HC-SR04 Ultrasound sensor
- SG90 Servo
- TB6612FNG Motor Driver
- 2 Yellow TT DC Motors
- Wires to connect breadboard to Arduino
- 2x 6V/9V Battery

# How It Works
The robot measures the distance in front of it using the HC-SR04 ultrasonic sensor.

When an obstacle is detected within a certain distance, the robot stops and scans the surroundings by turning the sensor left and right using the SG90 servo.

It compares the distances detected on both sides and turns toward the direction with more available space. It then continues moving forward and repeats the process.

# Challenges Encountered

Problem 1: Robot Body

Issue: Building a robot chassis using limited materials.

Cause: I wanted to save money and build my own chassis instead of purchasing a commercial one.

Solution: After researching and comparing my design with a typical 4WD Smart Robot Car Chassis Kit, I realised that I only needed to make two holes for the motor wires. This allowed the motors to be attached to the cardboard body while keeping the remaining components on top.

Problem 2: Battery Pack

Issue: Grease leaked from my original 6V battery pack.

Cause: There was a problem with the battery pack that I did not feel comfortable handling.

Solution: I replaced the damaged battery pack with a 9V battery supply using a 9V battery clip connector and the remaining wires to connect it to the motor driver.

Problem 3: Arduino Power Supply

Issue: I did not have a barrel jack to power the Arduino.

Cause: My available power supply did not have the required connector.

Solution: I used a power bank to supply power to the Arduino while carrying the robot.

# What I Learned

I was able to understand how different components work together to make a self-moving robot. I also learned how to use sensors to detect obstacles and make the robot decide which direction to turn.
I was also able to learn how to solve problems when working with limited materials and dealing with the robot's body and power supply.

# Robot Body Setup Images
It shows how I setup the Motors without using any glue gun and with simply 3 rubber bands. (Bottom side of the Car)

# Finalized images
It shows the final setup of my project

# Steps
-Gather all the materials.

-Cut a slit at the front centre of the cardboard, ensuring it is not too large.

-Follow the Robot Body Setup images to mount the motors.

-Secure the breadboard using rubber bands.

-Attach the two drive wheels to the motor shafts.

-Insert the remaining wheel into a stick and tape it underneath the chassis, next to the slit.

-Use the remaining rubber bands to attach the SG90 servo and HC-SR04 sensor.

-Secure the SG90 servo in the available space in front of the slit using a glue gun.


