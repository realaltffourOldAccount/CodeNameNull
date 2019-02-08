#ifndef L298N_HELPER_H
#define L298N_HELPER_H

// L298N
#define L298N_LEFT_CHANNEL_FRONT 51
#define L298N_LEFT_CHANNEL_BACK 53

#define L298N_RIGHT_CHANNEL_FRONT 47
#define L298N_RIGHT_CHANNEL_BACK 49

#define L298N_TURN_ON_PIN 45
// L298N

bool _isOn = false;

bool isL298N_On() { return _isOn; }
bool isL298N_Off() { return !_isOn; }

// Turn on the L298N
void onL298N() {
    pinMode(L298N_TURN_ON_PIN, OUTPUT);
    digitalWrite(L298N_TURN_ON_PIN, HIGH);
    _isOn = true;
}

// Turn off the L298N
void offL298N() {
    pinMode(L298N_LEFT_CHANNEL_FRONT, OUTPUT);
    pinMode(L298N_LEFT_CHANNEL_BACK, OUTPUT);
    pinMode(L298N_RIGHT_CHANNEL_FRONT, OUTPUT);
    pinMode(L298N_RIGHT_CHANNEL_BACK, OUTPUT);

    digitalWrite(L298N_LEFT_CHANNEL_FRONT, LOW);
    digitalWrite(L298N_LEFT_CHANNEL_BACK, LOW);
    digitalWrite(L298N_RIGHT_CHANNEL_FRONT, LOW);
    digitalWrite(L298N_RIGHT_CHANNEL_BACK, LOW);
    digitalWrite(L298N_TURN_ON_PIN, LOW);
}

// Steady
void steadyCar() {
    pinMode(L298N_LEFT_CHANNEL_FRONT, OUTPUT);
    pinMode(L298N_LEFT_CHANNEL_BACK, OUTPUT);
    pinMode(L298N_RIGHT_CHANNEL_FRONT, OUTPUT);
    pinMode(L298N_RIGHT_CHANNEL_BACK, OUTPUT);

    digitalWrite(L298N_LEFT_CHANNEL_FRONT, LOW);
    digitalWrite(L298N_LEFT_CHANNEL_BACK, LOW);
    digitalWrite(L298N_RIGHT_CHANNEL_FRONT, LOW);
    digitalWrite(L298N_RIGHT_CHANNEL_BACK, LOW);
}

// Forward
void moveCarForward() {
    if (!_isOn) return;
    pinMode(L298N_RIGHT_CHANNEL_FRONT, OUTPUT);
    digitalWrite(L298N_RIGHT_CHANNEL_FRONT, HIGH);
}

// BackWard
void moveCarBackward() {
    if (!_isOn) return;
    pinMode(L298N_RIGHT_CHANNEL_BACK, OUTPUT);
    digitalWrite(L298N_RIGHT_CHANNEL_BACK, HIGH);
}

// Right
void turnCarRight() {
    if (!_isOn) return;
    pinMode(L298N_LEFT_CHANNEL_BACK, OUTPUT);
    digitalWrite(L298N_LEFT_CHANNEL_BACK, HIGH);
}

// Left
void turnCarLeft() {
    if (!_isOn) return;
    pinMode(L298N_LEFT_CHANNEL_FRONT, OUTPUT);
    digitalWrite(L298N_LEFT_CHANNEL_FRONT, HIGH);
}

// Right Forward
void moveCarRightForward() {
    if (!_isOn) return;
    turnCarRight();
    moveCarForward();
}

// Left Forward
void moveCarLeftForward() {
    if (!_isOn) return;
    turnCarLeft();
    moveCarForward();
}

// Right BackWard
void moveCarRightBackward() {
    if (!_isOn) return;
    turnCarRight();
    moveCarBackward();
}

// Left BackWard
void moveCarLeftBackward() {
    if (!_isOn) return;
    turnCarLeft();
    moveCarBackward();
}

#endif
