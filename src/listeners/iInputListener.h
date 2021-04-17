#pragma once

#include "../components/iInputComponent.h"

class IInputListener
{
    public:
    virtual const char* getTypeName() const = 0;
    virtual const void onComponentEvent(    const IInputComponent* component, 
                                            EventType event,
                                            uint8_t outputButton) = 0; 
};


