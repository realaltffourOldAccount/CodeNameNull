# Drone Project Detials
Drone_Project
  Remote Programming Notes:
   The remote board will have two joystick and four buttons, 1 HC-04, 1 LCD DISPLAY SHIELD
   an arduino uno
   
   The left joystick will have two axis: x and y.
   The X axis will have a range from 0 to 1023
   The Y axis will have a range from 0 to 1023
   The normal state of X is 494
   The normal state of Y is 496
   
   X axis:
   
   The X axis will control the movement of the drone to the left with the range of tilt depending on the joystick(i.e from 494 to 1023)
   The Negative X axis will control the movement of the drone to the right  with the range of tilt depending on the joystick(i.e from 494 to 0)
   
   Y axis:
   
   The Y axis will control the movmennt of the drone to the front with the range of tilt depending on the joystick (i.e from 496 to 1023)
   The Negateve Y axis will control the movement of the drone to the back with the range of tilt depending on the Joystick (i.e from 496 to 0)
   
   SW Button:
  
   STABLE MODE:
   
   the button of the left joystick is used to stabilize the drone and make so if it was moved by another external object it will stay stable at the appropiate hight
   
   The right joystick will have two axis: x and y
   The X axis will have a range from 0 to 1023
   The Y axis will have a range from 0 to 1023
   The normal state of X is 502
   The normal state of Y is 510
   
   X axis:
   
   The Y axis will control the thrust of the engines on the drone if the joystick is on normal state the engine will be off or running on enough power to hold the drone depending 
   on the mode choosen
   The X axis will control the rotation of the drone, the more the stick is on left it will rotate anticlockwise and vise versa
   
   SW button:
   
   ABORT:
   
   Used for auto landing, normally in case of emergency
   
   The negative is the value which is below the normal state of an axis on the joystick
   
   The button will be laid on the remote as a square
   Button 1 will be on the top left
   And button 2 will be on the top right
   And button 3 will be on the buttom left
   And button 4 will be on the buttom right
   
   Button 1:
   
   the output of the button will be connected on the arduino PWM11
   Use:
   
   Enable safe mode
   Safe mode is a mode that ensourse that the plan will not fall below 30 cm
   Better to be used when doing stunts for saftey measures. 
   WARNING THIS DOES NOT WORKING WITH 360 MODE ENABLED
   
   Button 2:
   
   the output of the button will be connected on the arduino PWM10
   Use:
   Enable disable safety measures
   To turn off or on the all safety measure. just like manuall flight.
   This clearly puts all the responsiblity on the pilot of the drone. AND THE PROGRAM HAVE NOTHING TO DO IN CASE OF A CRASH
   
   Button 3:
   
   the output of the button will be connected on the arduino PWM9
   Use:
   Enable/Disable Lights:
   Enable the lights on the drone representing the drone mode.
   
   Button 4:
   
   the output of the button will be connected on teh arduino DIG8
   Use:
   Enable Revirse thrust:
   This enables the engines to reverse thrust, and bring the drone lower faster.
   This should not be used only in stunts
   NOTE: THIS ONLY ENABLE OR DISABLES THE NEGATIVE PART OF THE RIGHT Y AXIS JOYSTICK

Drone Programming Code:

Notes:

The drone will have onboard 1 ARDU MEGA, 2 ULTRA-SOUND SENSOR, 2 L298N, 4 LED lights, 1 HC-04 bluetooth,
4 7800RPM engines, 4 PROPS

2 engines will run CCW since two props angle of attack is inverted
Engine power will be pareller in plain flight, engine power, direction will be manipulated depending on 
the controllers.

LEDS:

will indicate the state of the drone
If green, the drone is safe to be close at
If blue, the drone is on stable mode ON and it is safe to some extinct
If red, the drone is on manuall and the drone is not safe to be close at.

Joystick recap:

JS1:

X from 0 1023
Y from 0 1023
MID X 
JS2:

X from 0 1023
Y from 0 1023


Engine Managment:

Not Completed
