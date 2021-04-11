#include <Arduino.h>

#include "displayManager.h"
#include "components/inputComponent.h"
#include "components/buttonComponent.h"
#include "components/componentIds.h"
#include "listeners/iInputListener.h"
#include "listeners/LedListener.h"


#define PIN_BUILT_IN_BTN_LEFT 0
#define PIN_BUILT_IN_BTN_RIGHT 35

DisplayManager m_DisplayManager;

// TODO: Refactor these into an array
ButtonComponent m_Button1(PIN_BUILT_IN_BTN_LEFT, Component::kBuiltinButtonLeft, true);
ButtonComponent m_Button2(PIN_BUILT_IN_BTN_RIGHT, Component::kBuiltinButtonRight, true);

uint8_t ESP32_LED_BUILTIN = 27;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  m_DisplayManager.begin();

  // TODO: Refactor these into a function, RegisterListeners and use array
  m_Button1.RegisterListener(new SerialInputListener());
  m_Button2.RegisterListener(new SerialInputListener());
  //m_Button1.RegisterListener(new LedListener(LED_BUILTIN));

  //pinMode(ESP32_LED_BUILTIN, OUTPUT);
}

void loop() {

  // TODO: Use array
  m_Button1.onLoop();
  m_Button2.onLoop();

  delay(100);
}