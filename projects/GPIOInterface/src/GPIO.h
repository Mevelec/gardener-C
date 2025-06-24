#pragma once

#include <cstdint>

enum class PinMode {
    INPUT,
    OUTPUT
};

enum class PinState {
    LOW = 0,
    HIGH = 1
};

class GPIO {
public:
    GPIO(int pinNumber);
    ~GPIO();

    // Initialize the pin with a mode
    bool configure(PinMode mode);

    // Read the current state of the pin (digital input)
    PinState read() const;

    // Write a digital value to the pin (digital output)
    bool write(PinState state);

    // Toggle the current state
    bool toggle();

    // Set internal pull-up or pull-down resistors if supported
    bool setPullUp(bool enabled);
    bool setPullDown(bool enabled);

    // Get pin number
    int getPin() const;

    // Static methods for managing multiple pins might be added here

private:
    int pinNumber_;
    PinMode mode_;
    // Add hardware-specific members here (e.g., file handles, register addresses)
    
    // Platform-specific implementations
    bool initializeHardware();
    bool cleanupHardware();
};