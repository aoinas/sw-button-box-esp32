#pragma once

#include <Arduino.h>
#include <BleGamepad.h> 

#include "iInputListener.h"
#include "../components/componentIds.h"
#include "../components/buttonComponent.h"

class BleGamepadListener : public IInputListener
{
    public:
    BleGamepadListener(uint16_t buttonCount) : _bleGamepad()
    {
        _bleGamepad.setAutoReport(false);
        _bleGamepad.setControllerType(CONTROLLER_TYPE_GAMEPAD);  //CONTROLLER_TYPE_JOYSTICK, CONTROLLER_TYPE_GAMEPAD (DEFAULT), CONTROLLER_TYPE_MULTI_AXIS
        _bleGamepad.begin(buttonCount,0);        //Simulation controls are disabled by default
    }

    virtual const char* getTypeName() const override { return "Bluetooth Gamepad Listener"; }
 
    virtual const void onComponentEvent(const IInputComponent* component, 
                                        EventType event,
                                        uint8_t outputButton) override
    {
        if(_bleGamepad.isConnected()) 
        {
            switch (event)
            {
                case kButtonPressed:
                    _bleGamepad.press(outputButton);
                    break;

                case kButtonReleased:
                    _bleGamepad.release(outputButton);
                    break;

                default:
                    Serial.println("BleGamepadListener: Unknown button event");
                    break;
            }
        }
        else
        {
            Serial.println("BleGamepadListener received event but it is not connected");
        }  
    } 

    private:
    BleGamepad _bleGamepad;

};