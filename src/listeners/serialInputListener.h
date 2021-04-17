#pragma once

#include "Arduino.h"
#include "iInputListener.h"

class SerialInputListener : public IInputListener
{
    virtual const char* getTypeName() const override { return "Serial Input Listener"; }
    virtual const void onComponentEvent(const IInputComponent* component, 
                                        EventType event,
                                        uint8_t outputButton) override
    {
        //Serial.println("SerialInputListener::onComponentEvent: Start");
        
        const char* eventName;

        switch (event)
        {
        case kButtonPressed:
            eventName = "pressed";
            break;
        
        case kButtonReleased:
            eventName = "released";
            break;

        default:
            eventName = "done something, but dunno what";
            break;
        }

        char msg[200];
        sprintf(msg, "%s was %s. Output button: %d", 
                component->getName(), 
                eventName,
                outputButton );
        Serial.println(msg);

    }
};