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
        _isPressed(false), 
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
        //Serial.printf("onLoop: Button %d", _pin);
        int currentState = digitalRead(_pin) ;

        bool isCurrentlyPressed = currentState == _isInversed ? LOW : HIGH;


        if ( isCurrentlyPressed != _isPressed)
        {
            _isPressed = isCurrentlyPressed;
            NotifyListeners(_isPressed ? kButtonPressed : kButtonReleased);
        }
    }

    private:
    uint8_t _pin;
    bool _isPressed; 
    bool _isInversed; 
    char _componentName[50];
   
};


