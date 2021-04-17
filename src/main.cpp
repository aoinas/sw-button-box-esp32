#include <Arduino.h>
#include <Vector.h>

#include "displayManager.h"
#include "components/inputComponent.h"
#include "components/buttonComponent.h"
#include "components/componentIds.h"
#include "listeners/iInputListener.h"
#include "listeners/serialInputListener.h"
#include "listeners/LedListener.h"

#define PIN_BUILT_IN_BTN_LEFT 0
#define PIN_BUILT_IN_BTN_RIGHT 35

#define MAX_INPUT_COMPONENT_COUNT 32
Vector<InputComponent*> m_InputComponents;
InputComponent* m_InputComponentsContainer[MAX_INPUT_COMPONENT_COUNT];

DisplayManager m_DisplayManager;
// TODO: Refactor these into an array

// Listeners
SerialInputListener m_SerialInputListener;

static void registerListeners(Vector<InputComponent*>& components)
{
  for (int i=0; i<components.size(); i++)
  {
    m_InputComponents[i]->RegisterListener(&m_SerialInputListener);
  }
} 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  m_DisplayManager.begin();
  m_InputComponents.setStorage(m_InputComponentsContainer);

  // Create input components
  m_InputComponents.push_back(new ButtonComponent(PIN_BUILT_IN_BTN_LEFT, Component::kBuiltinButtonLeft, true));
  m_InputComponents.push_back(new ButtonComponent(PIN_BUILT_IN_BTN_RIGHT, Component::kBuiltinButtonRight, true));
 
  registerListeners(m_InputComponents);
}


void loop() {

  /* for (auto c : m_InputComponents)
    c->onLoop();
 */
  //for (int i=0; i < m_InputComponents.size(); i++)
   // m_InputComponents.at(i)->onLoop();
    //m_InputComponents[i]->onLoop();

  m_InputComponents[0]->onLoop();
  m_InputComponents[1]->onLoop();

  int currentState = digitalRead(PIN_BUILT_IN_BTN_LEFT);

  Serial.printf("Left btn pin status %i", currentState);
  Serial.println();

  delay(2000);
}