#pragma once
#include <Arduino.h>

#include "iInputComponent.h"
#include "componentIds.h"
#include "../listeners/iInputListener.h"

#define MAX_LISTENER_COUNT 2

class InputComponent : public IInputComponent
{
    public:
    InputComponent(Component component) : 
        _listeners(), 
        _listenerCount(0),
        _component(component)  
    {
    }

    virtual void onLoop() = 0;
    virtual const char* getName() const = 0; 

    bool RegisterListener(const IInputListener* listener)
    {
        if (_listenerCount < MAX_LISTENER_COUNT)
        {
            _listeners[_listenerCount] = listener;
            _listenerCount++;
            char s[100];
            sprintf(s, "Registered listener '%s' for component '%s'", 
                listener->getTypeName(),
                getName());
            Serial.println(s);
            return true;
        }
        else
        {
            Serial.println("Failed to register listener because max amount of listeners are already registered");
            return false;
        }
    }

    bool NotifyListeners(EventType event)
    {
        for (uint8_t i=0; i < _listenerCount; i++)
            _listeners[i]->onComponentEvent(this, event);

        return true;
    }

    private:
    const IInputListener* _listeners[MAX_LISTENER_COUNT];
    int _listenerCount;
    Component _component;
};