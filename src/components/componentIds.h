#pragma once

enum Component {
    kNotDefined = 0,
    kBuiltinButtonLeft = 1,
    kBuiltinButtonRight = 2
    // 4, 8, etc...
};

enum EventType {
//    kNotDefined = 0,
    kButtonPressed = 1,
    kButtonReleased = 2
    // 4, 8, etc...
};