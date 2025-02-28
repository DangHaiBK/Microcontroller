#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN   PA6
#define BUTTON_PIN  PC13

volatile uint8_t countButtonTimes;
int values[] = {1000, 1500, 2000, 1500};

Servo myServo;

void servoSetPosition();

void setup() {
  // put your setup code here, to run once:
  myServo.attach(SERVO_PIN);

  delay(1000);

  myServo.writeMicroseconds(1500);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  attachInterrupt(BUTTON_PIN, servoSetPosition, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// uint16_t getValueFromButton(uint8_t count) {
//   uint16_t values[] = {1500, 1000, 2000};
//   return values[(count - 1) % 3];
// }

void servoSetPosition() {
  countButtonTimes ++;
  myServo.writeMicroseconds(values[(countButtonTimes - 1) % 4]);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}