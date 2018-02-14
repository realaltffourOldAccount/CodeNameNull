# Arduino Drone Project Detials <br />

  Remote Programming Notes:<br />
   The remote board will have two joystick and four buttons, 1 HC-04, 1 LCD DISPLAY SHIELD<br />
   an arduino uno<br />
   
   The left joystick will have two axis: x and y.<br />
   The X axis will have a range from 0 to 1023<br />
   The Y axis will have a range from 0 to 1023<br />
   The normal state of X is 494<br />
   The normal state of Y is 496<br />
   
   X axis:<br />
   
   The X axis will control the movement of the drone to the left with the range of tilt depending on the joystick(i.e from 494 to 1023)<br />
   The Negative X axis will control the movement of the drone to the right  with the range of tilt depending on the joystick(i.e from 494 to 0)<br />
   
   Y axis:<br />
   The Y axis will control the movmennt of the drone to the front with the range of tilt depending on the joystick (i.e from 496 to 1023)<br />
   The Negateve Y axis will control the movement of the drone to the back with the range of tilt depending on the Joystick (i.e from 496 to 0)<br />
   
   SW Button:<br />
   STABLE MODE:<br />
   the button of the left joystick is used to stabilize the drone and make so if it was moved by another external object it will stay stable at the appropiate hight<br />
   
   The right joystick will have two axis: x and y<br />
   The X axis will have a range from 0 to 1023<br />
   The Y axis will have a range from 0 to 1023<br />
   The normal state of X is 502<br />
   The normal state of Y is 510<br />
   
   X axis:<br />
   The Y axis will control the thrust of the engines on the drone if the joystick is on normal state the engine will be off or running on enough power to hold the drone depending <br />
   on the mode choosen<br />
   The X axis will control the rotation of the drone, the more the stick is on left it will rotate anticlockwise and vise versa<br />
   
   SW button:<br />
   ABORT:<br />
   Used for auto landing, normally in case of emergency<br />
   The negative is the value which is below the normal state of an axis on the joystick<br />
   
   The button will be laid on the remote as a square<br />
   Button 1 will be on the top left<br />
   And button 2 will be on the top right<br />
   And button 3 will be on the buttom left<br />
   And button 4 will be on the buttom right<br />
   
   Button 1:<br />
   the output of the button will be connected on the arduino PWM11<br />
   Use:<br />
   Enable safe mode<br />
   Safe mode is a mode that ensourse that the plan will not fall below 30 cm<br />
   Better to be used when doing stunts for saftey measures. <br />
   WARNING THIS DOES NOT WORKING WITH 360 MODE ENABLED<br />
   
   Button 2:<br />
   the output of the button will be connected on the arduino PWM10<br />
   Use:<br />
   Enable disable safety measures<br />
   To turn off or on the all safety measure. just like manuall flight.<br />
   This clearly puts all the responsiblity on the pilot of the drone. AND THE PROGRAM HAVE NOTHING TO DO IN CASE OF A CRASH<br />
   
   Button 3:<br />
   the output of the button will be connected on the arduino PWM9<br />
   Use:<br />
   Enable/Disable Lights:<br />
   Enable the lights on the drone representing the drone mode.<br />
   
   Button 4:<br />
   the output of the button will be connected on teh arduino DIG8<br />
   Use:<br />
   Enable Revirse thrust:<br />
   This enables the engines to reverse thrust, and bring the drone lower faster.<br />
   This should not be used only in stunts<br />
   NOTE: THIS ONLY ENABLE OR DISABLES THE NEGATIVE PART OF THE RIGHT Y AXIS JOYSTICK<br />

Drone Programming Code:

Notes:
The drone will have onboard 1 ARDU MEGA, 2 ULTRA-SOUND SENSOR, 2 L298N, 4 LED lights, 1 HC-04 bluetooth,<br />
4 7800RPM engines, 4 PROPS<br />
2 engines will run CCW since two props angle of attack is inverted<br />
Engine power will be pareller in plain flight, engine power, direction will be manipulated depending on <br />
the controllers.<br />

LEDS:<br />
will indicate the state of the drone<br />
If green, the drone is safe to be close at<br />
If blue, the drone is on stable mode ON and it is safe to some extinct<br />
If red, the drone is on manuall and the drone is not safe to be close at.<br />

Joystick recap:<br />
JS1:<br />

X from 0 1023<br />
Y from 0 1023<br />
MID X <br />
JS2:<br />
X from 0 1023<br />
Y from 0 1023<br />

Engine Managment:<br />
Not Completed<br />
