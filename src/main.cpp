#include <Arduino.h>
#include <LowPower.h>

const int wakeUpPin = 2;

void wakeUp() {

}

void setup() {
  // put your setup code here, to run once:
  pinMode(wakeUpPin, INPUT_PULLUP);
}

void loop() {
  attachInterrupt(digitalPinToInterrupt(wakeUpPin), wakeUp, FALLING);

  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  detachInterrupt(wakeUpPin);

  Serial.begin(9600);
  delay(10);
  Serial.println(F("Hello World!!"));
  Serial.flush();
  Serial.end();

}