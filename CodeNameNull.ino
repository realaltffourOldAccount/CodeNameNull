#include <SoftwareSerial.h>

// UTILITIES
#include "ButtonsHelper.h"
#include "L298N_Helper.h"
#include "LedHelper.h"
#include "SensorHelper.h"

// UTILITIES

short _choosen_style = -1;

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
style:
  int on_btn = getBtnOn();
  if (on_btn == -1) goto style;
  _choosen_style = on_btn;
};

void setup() {
  initBtns();
  onL298N();
  // steadyCar();
  alertStartup();
  setStyle();
}

void loop() {}
