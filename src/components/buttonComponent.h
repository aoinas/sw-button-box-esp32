#pragma once

#include <Arduino.h>
#include "inputComponent.h"
#include "componentIds.h"

class ButtonComponent : public InputComponent
{
    public:
    ButtonComponent(    uint8_t pin, 
                        Component component, 
                        uint8_t gamePadButtonNo, 
                        bool isInversed = false) : 
        InputComponent(component), 
        _pin(pin), 
        _isPressed(false), 
        _gamePadButtonNo(gamePadButtonNo),
        _isInversed(isInversed),
        _componentName("")
    {
        pinMode(_pin, INPUT);

        sprintf(    _componentName, 
                    "Button on pin %d, binded to gamepad button %d",
                     _pin, 
                     _gamePadButtonNo);
    }

    virtual const char* getName() const override
    {
        return _componentName;
    }

    uint8_t getButton() const { return _gamePadButtonNo; }

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
    uint8_t _gamePadButtonNo; 
    bool _isInversed; 
    char _componentName[50];
    
   
};


