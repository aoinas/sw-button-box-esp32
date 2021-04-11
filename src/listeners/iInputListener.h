#pragma once

#include "../components/componentIds.h"

class IInputListener
{
    public:
    virtual const char* getTypeName() const = 0;

    virtual const void onComponentEvent(const Component component, EventType event) const = 0; // TODO: Refactor Component to IInputComponent
};


// TODO: move to its own file
class SerialInputListener : public IInputListener
{
    virtual const char* getTypeName() const override { return "Serial Input Listener"; }
    virtual const void onComponentEvent(Component component, EventType event) const override
    {
        const char* componentName;
        switch (component)
        {
        case kBuiltinButtonLeft:
            componentName = "Left builtin button";
            break;

        case kBuiltinButtonRight:
            componentName = "Right builtin button";
            break;
        
        default:
            componentName = "Unknown";
            break;
        }

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
        sprintf(msg, "%s was %s", componentName, eventName );
        Serial.println(msg);

    };
};