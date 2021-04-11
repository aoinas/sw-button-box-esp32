#pragma once
#include <Arduino.h>
#include "iInputListener.h"

class LedListener : public IInputListener
{
    public:
    LedListener(uint8_t pin) : _pin(pin) {
        pinMode(_pin, OUTPUT);
        digitalWrite(_pin, LOW);
    };

    virtual const char* getTypeName() const override { return "LED Listener"; }

    private:
    uint8_t _pin;
};