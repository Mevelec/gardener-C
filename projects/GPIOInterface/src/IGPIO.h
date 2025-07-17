#pragma once

#include <cstdint>
#include "GPIOInterfaceAPIExport.h"

enum class GPIO_INTERFACE PinMode {
    INPUT,
    OUTPUT
};

enum class GPIO_INTERFACE PinState {
    LOW = 0,
    HIGH = 1
};

class GPIO_INTERFACE IGPIO {
public:
    virtual ~IGPIO() = default;

    virtual bool setMode(PinMode mode) = 0;
    virtual PinState read() const = 0;
    virtual bool write(PinState state) = 0;
    virtual bool toggle() = 0;
    virtual bool setPullUp(bool enabled) = 0;
    virtual bool setPullDown(bool enabled) = 0;
    virtual int getPin() const = 0;
};