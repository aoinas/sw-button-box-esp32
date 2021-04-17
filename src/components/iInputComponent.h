#pragma once

class IInputComponent
{
    public:
    virtual void onLoop() = 0;
    virtual const char* getName() const = 0; 
};