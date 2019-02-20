#include <SoftwareSerial.h>
// UTILITIES
#include "L298N_Helper.h"
#include "LedHelper.h"
#include "SensorHelper.h"

#include <string.h>

// UTILITIES

short int _choosen_style = 1;
// STYLE1: BACK AND FRONT, REVERSE WHEN SENSOR <= 5cm
// STYLE2: Draw X, Stop when SENSOR <= 5cm
// STYLE3: Circle, Stop when SENSOR <= 10cm
// STYLE4: HAND DRIVING, Move when sensor <= 5cm

void alertStartup() {
  setAll_Red();
  delay(5000);

  setLed1_Green();
  delay(500);
  setLed2_Green();
  delay(500);
  setLed3_Green();
  delay(500);
  setLed4_Green();
  delay(500);

  for (int i = 0; i < 10; i++) {
    offAll();
    delay(25);
    setAll_Red();
    delay(25);
    setAll_Green();
    delay(25);
    setAll_Blue();
    offAll();
  }

  turnCarLeft();
  delay(500);
  turnCarRight();
  delay(500);

  setAll_Blue();
}

void setup() {
  // back sensor on
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);

  onL298N();
  steadyCar();
  alertStartup();
}

void loop() {
  /*
    ////// FIRST CHECK //////
    - If the front and rear sensor reads 5cm or less the car steadies.

    ////// SECOND CHECK ///////
    - If the front sensor reads 5cm or less the car goes backwards.
    - If the rear sensor reads 5cm or less the car goes forwards.

    ////// THIRD CHECK ///////
    - If the front sensor reads between: (5...10), the car will go to the front
    and steer right
    - If the front sensor reads between: (10...15), the car will go to the front
    and steer left.
    - If the rear sensor reads between: (5...10), the car will go to the rear
    and steer right.
    - If the rear sensor reads between: (10...15), the car will go the rear and
    steer left

    /////// FOURTH CHECK /////
    - If any sensor reads above 15cm the car will go to the choosen path.

  */

  ///////// VARS////////
  // front - 1 == car goes forwards
  // front - 0 == car steadys
  // front - -1 == car goes backwards
  int front = 0;
  // right - 1 == car goes right (back or front doesnt matter).
  // right - 0 == car goes straight (back or front doesnt matter).
  // right - -1 == car goes left (back or front doenst matter).
  int right = 0;
  //////////////////////

  while (1) {
    // read from the sensors
    long front_sensor = getFrontSensor();
    long rear_sensor = getRearSensor();

    /// STEP 1
    if ((front_sensor < 5) && (rear_sensor < 5))  // steady confirmed
      front = 0;
    /// STEP 2
    else if (front_sensor < 5)
      front = -1;
    else if (rear_sensor < 5)
      front = 1;
    /// STEP 3
    else if ((front_sensor >= 5) && (front_sensor <= 10))
      right = 1;
    else if ((front_sensor >= 10) && (front_sensor <= 15))
      right = -1;
    else if ((rear_sensor >= 5) && (rear_sensor <= 10))
      right = 1;
    else if ((rear_sensor >= 10) && (rear_sensor <= 15))
      right = -1;

    // Execute the choosen path
    if (front == 1) moveCarForward();
    if (front == -1) moveCarBackward();
    if (right == 1) turnCarRight();
    if (right == -1) turnCarLeft();

    if (front == 0 && right == 0)
      steadyCar();
    else if (front == 0)
      steadyCar();
  }
}