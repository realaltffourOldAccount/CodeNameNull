#ifndef LED_HELPER_H
#define LED_HELPER_H

// LED
#define STATE_LED1_RED A0
#define STATE_LED1_GREEN A1
#define STATE_LED1_BLUE A2

#define STATE_LED2_RED A3
#define STATE_LED2_GREEN A4
#define STATE_LED2_BLUE A5

#define STATE_LED3_RED A6
#define STATE_LED3_GREEN A7
#define STATE_LED3_BLUE A8

#define STATE_LED4_RED A9
#define STATE_LED4_GREEN A10
#define STATE_LED4_BLUE A11
// LED

// TURN ON FUNCS

// Set led1 red
void setLed1_Red() {
  pinMode(STATE_LED1_RED, OUTPUT);
  digitalWrite(STATE_LED1_RED, HIGH);
}

// Set led1 green
void setLed1_Green() {
  pinMode(STATE_LED1_GREEN, OUTPUT);
  digitalWrite(STATE_LED1_GREEN, HIGH);
}

// Set led1 blue
void setLed1_Blue() {
  pinMode(STATE_LED1_BLUE, OUTPUT);
  digitalWrite(STATE_LED1_BLUE, HIGH);
}

// Set led2 red
void setLed2_Red() {
  pinMode(STATE_LED2_RED, OUTPUT);
  digitalWrite(STATE_LED2_RED, HIGH);
}

// Set led2 green
void setLed2_Green() {
  pinMode(STATE_LED2_GREEN, OUTPUT);
  digitalWrite(STATE_LED2_GREEN, HIGH);
}

// Set led2 blue
void setLed2_Blue() {
  pinMode(STATE_LED2_BLUE, OUTPUT);
  digitalWrite(STATE_LED2_BLUE, HIGH);
}

// Set led3 red
void setLed3_Red() {
  pinMode(STATE_LED3_RED, OUTPUT);
  digitalWrite(STATE_LED3_RED, HIGH);
}

// Set led3 green
void setLed3_Green() {
  pinMode(STATE_LED3_GREEN, OUTPUT);
  digitalWrite(STATE_LED3_GREEN, HIGH);
}

// Set led3 blue
void setLed3_Blue() {
  pinMode(STATE_LED3_BLUE, OUTPUT);
  digitalWrite(STATE_LED3_BLUE, HIGH);
}

// Set led4 red
void setLed4_Red() {
  pinMode(STATE_LED4_RED, OUTPUT);
  digitalWrite(STATE_LED4_RED, HIGH);
}

// Set led4 green
void setLed4_Green() {
  pinMode(STATE_LED4_GREEN, OUTPUT);
  digitalWrite(STATE_LED4_GREEN, HIGH);
}

// Set led4 blue
void setLed4_Blue() {
  pinMode(STATE_LED4_BLUE, OUTPUT);
  digitalWrite(STATE_LED4_BLUE, HIGH);
}

/// TURN OFF FUNCS

// off led1 red
void offLed1_Red() {
  pinMode(STATE_LED1_RED, OUTPUT);
  digitalWrite(STATE_LED1_RED, LOW);
}

// off led1 green
void offLed1_Green() {
  pinMode(STATE_LED1_GREEN, OUTPUT);
  digitalWrite(STATE_LED1_GREEN, LOW);
}

// off led1 blue
void offLed1_Blue() {
  pinMode(STATE_LED1_BLUE, OUTPUT);
  digitalWrite(STATE_LED1_GREEN, LOW);
}

// off led2 red
void offLed2_Red() {
  pinMode(STATE_LED2_RED, OUTPUT);
  digitalWrite(STATE_LED2_RED, LOW);
}

// off led2 green
void offLed2_Green() {
  pinMode(STATE_LED2_GREEN, OUTPUT);
  digitalWrite(STATE_LED2_GREEN, LOW);
}

// off led2 blue
void offLed2_Blue() {
  pinMode(STATE_LED2_BLUE, OUTPUT);
  digitalWrite(STATE_LED2_BLUE, LOW);
}

// off led3 red
void offLed3_Red() {
  pinMode(STATE_LED3_RED, OUTPUT);
  digitalWrite(STATE_LED3_RED, LOW);
}

// off led3 green
void offLed3_Green() {
  pinMode(STATE_LED3_GREEN, OUTPUT);
  digitalWrite(STATE_LED3_GREEN, LOW);
}

// off led3 blue
void offLed3_Blue() {
  pinMode(STATE_LED3_BLUE, OUTPUT);
  digitalWrite(STATE_LED3_BLUE, LOW);
}

// off led4 red
void offLed4_Red() {
  pinMode(STATE_LED4_RED, OUTPUT);
  digitalWrite(STATE_LED4_RED, LOW);
}

// off led4 green
void offLed4_Green() {
  pinMode(STATE_LED4_GREEN, OUTPUT);
  digitalWrite(STATE_LED4_GREEN, LOW);
}

// off led4 blue
void offLed4_Blue() {
  pinMode(STATE_LED4_BLUE, OUTPUT);
  digitalWrite(STATE_LED4_BLUE, LOW);
}

// set all red
void setAll_Red() {
  setLed1_Red();
  setLed2_Red();
  setLed3_Red();
  setLed4_Red();
}

// set all green
void setAll_Green() {
  setLed1_Green();
  setLed2_Green();
  setLed3_Green();
  setLed4_Green();
}

// set all blue
void setAll_Blue() {
  setLed1_Blue();
  setLed2_Blue();
  setLed3_Blue();
  setLed4_Blue();
}

// turn off all
void offAll() {
  offLed1_Red();
  offLed1_Green();
  offLed1_Blue();

  offLed2_Red();
  offLed2_Green();
  offLed2_Blue();

  offLed3_Red();
  offLed3_Green();
  offLed3_Blue();

  offLed4_Red();
  offLed4_Green();
  offLed4_Blue();
}

#endif
