#ifndef SENSOR_HELPER_H
#define SENSOR_HELPER_H
// SENSORS
#define REAR_SENSOR_TRIGGER_PIN 31
#define REAR_SENSOR_RECIEVE_PIN 33

#define FRONT_SENSOR_TRIGGER_PIN 35
#define FRONT_SENSOR_RECIEVE_PIN 37
// SENSORS

// Converts the time tacken to recieve echo to centimeter
long SensorMsToCm(long microseconds) { return microseconds * 0.034 / 2; }

// Get the front sensor data, in centimeter
long getFrontSensor() {
  pinMode(FRONT_SENSOR_TRIGGER_PIN, OUTPUT);
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, LOW);
  pinMode(FRONT_SENSOR_RECIEVE_PIN, INPUT);
  long duration = pulseIn(FRONT_SENSOR_RECIEVE_PIN, HIGH);
  return SensorMsToCm(duration);
}

// Get the back sensor data, in centimeter
long getRearSensor() {
  pinMode(REAR_SENSOR_TRIGGER_PIN, OUTPUT);
  digitalWrite(REAR_SENSOR_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(REAR_SENSOR_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(REAR_SENSOR_TRIGGER_PIN, LOW);
  pinMode(REAR_SENSOR_RECIEVE_PIN, INPUT);
  long duration = pulseIn(REAR_SENSOR_RECIEVE_PIN, HIGH);
  return SensorMsToCm(duration);
}

#endif
