#pragma once

#include "../components/componentIds.h"

class IInputListener
{
    public:
    virtual const char* getTypeName() const = 0;

    virtual const void onComponentEvent(const Component component, EventType event) const = 0; // TODO: Refactor Component to IInputComponent
};


