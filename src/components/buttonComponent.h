#pragma once

#include <Arduino.h>
#include "inputComponent.h"
#include "componentIds.h"

class ButtonComponent : public InputComponent
{
    public:
    ButtonComponent(uint8_t pin, Component component, bool isInversed = false) : 
        InputComponent(component), 
        _pin(pin), 
        _state(LOW), 
        _isInversed(isInversed),
        _componentName("")
    {
        pinMode(_pin, INPUT);

        sprintf(_componentName, "Button on pin %d", _pin);
    }

    virtual const char* getName() const override
    {
        return _componentName;
    }

    virtual void onLoop() override
    {
        Serial.printf("onLoop: Button %d", _pin);
        int currentState = digitalRead(_pin);

        if ( currentState != _state)
        {
            _state = currentState;
            NotifyListeners(_state == HIGH ? kButtonPressed : kButtonReleased);
        }
    }

    private:
    uint8_t _pin;
    int _state; // TODO: refactor to bool _pressed. handle isInversed better
    bool _isInversed; // Does low mean pressed?
    char _componentName[50];
   
};


