#include <Arduino.h>

#include "displayManager.h"
DisplayManager m_DisplayManager;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  m_DisplayManager.Begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("I am alive!");
  delay(5000);
}