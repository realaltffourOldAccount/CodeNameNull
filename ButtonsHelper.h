#ifndef BUTTON_HELPER_H
#define BUTTON_HELPER_H

// BTNS
#define PIN_OUT_BTN1 38
#define PIN_OUT_BTN2 40
#define PIN_OUT_BTN3 42
#define PIN_OUT_BTN4 44

#define PIN_IN_BTN1 46
#define PIN_IN_BTN2 48
#define PIN_IN_BTN3 50
#define PIN_IN_BTN4 52
// BTNS

bool _isInit = false;

// inits the buttons
void initBtns() {
  pinMode(PIN_OUT_BTN1, OUTPUT);
  pinMode(PIN_OUT_BTN2, OUTPUT);
  pinMode(PIN_OUT_BTN3, OUTPUT);
  pinMode(PIN_OUT_BTN4, OUTPUT);
  _isInit = true;
}

// Turns on the buttons vcc
void turnOnBtns() {
  if (!_isInit) return;
  digitalWrite(PIN_OUT_BTN1, HIGH);
  digitalWrite(PIN_OUT_BTN2, HIGH);
  digitalWrite(PIN_OUT_BTN3, HIGH);
  digitalWrite(PIN_OUT_BTN4, HIGH);
}

// Get turned on btn index
int getBtnOn() {
  if (digitalRead(PIN_IN_BTN1) != HIGH)
    return 1;
  else if (digitalRead(PIN_IN_BTN2) != HIGH)
    return 2;
  else if (digitalRead(PIN_IN_BTN3) != HIGH)
    return 3;
  else if (digitalRead(PIN_IN_BTN4) != HIGH)
    return 4;

  return -1;
}

#endif