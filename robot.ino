#include "robot.h"

void setup() {
  
  Serial.begin(115200);

  pinMode(FRONT_PIN, INPUT);
  pinMode(FULL_RIGHT_PIN, INPUT);
  pinMode(FULL_LEFT_PIN, INPUT);
  pinMode(LEFT_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);

  pinMode(RIGHT_MOTOR_PWM_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_IN_PIN_1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN_PIN_2, OUTPUT);
  pinMode(LEFT_MOTOR_PWM_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_IN_PIN_1, OUTPUT);
  pinMode(LEFT_MOTOR_IN_PIN_2, OUTPUT);

  pinMode(MICRO_START_INPUT_PIN, INPUT);

  pinMode(STDBY, OUTPUT);
  digitalWrite(STDBY, HIGH);

  ledcAttachPin(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_CHANNEL);
  ledcSetup(RIGHT_MOTOR_CHANNEL, 12000, 8);

  ledcAttachPin(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_CHANNEL);
  ledcSetup(LEFT_MOTOR_CHANNEL, 12000, 8);

}

void loop() {
  
  static Robot tobor;

  tobor.update();

}