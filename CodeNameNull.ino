#include <SoftwareSerial.h>

// UTILITIES
#include "ButtonsHelper.h"
#include "L298N_Helper.h"
#include "LedHelper.h"
#include "SensorHelper.h"

// UTILITIES

short _choosen_style = -1;
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

void setStyle() {
    int on_btn;
    while (on_btn == -1) on_btn = getBtnOn();
    _choosen_style = on_btn;
};

// STYLE1: BACK AND FRONT, REVERSE WHEN SENSOR <= 5cm
void style1_exec() {
    bool front = true;
    while (1) {
        if ((getFrontSensor() <= 5) || (getRearSensor() <= 5)) front = !front;

        if (front)
            moveCarForward();
        else
            moveCarBackward();
    }
}
// STYLE2: Draw X, Stop when SENSOR <= 5cm
void style2_exec() {}
// STYLE3: Circle, Stop when SENSOR <= 10cm
void style3_exec() {}
// STYLE4 : HAND DRIVING, Move when sensor <= 5cm
void style4_exec() {}

void executeStyle() {
    switch (_choosen_style) {
        case 1:
            style1_exec();
            break;
        case 2:
            style2_exec();
            break;
        case 3:
            style3_exec();
            break;
        case 4:
            style4_exec();
            break;
        default:
            break;
    }
}

void setup() {
    initBtns();
    onL298N();
    steadyCar();
    alertStartup();
    setStyle();
}

void loop() {}
