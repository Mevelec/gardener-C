#include <stdexcept>
#include <iostream>
#include "GPIO_Pigpio.h"
#include <pigpiod_if2.h>
#include <LoggerAPI.h>
#include "Pigpio_Connection.h"

GPIO_Pigpio::GPIO_Pigpio(int pinNumber) : pinNumber_(pinNumber) {
    Pigpio_Connection& connection = Pigpio_Connection::getInstance();
}

GPIO_Pigpio::~GPIO_Pigpio() {
}

bool GPIO_Pigpio::setMode(PinMode mode) {
    CORE_ERROR("Not Yet Implemented");
    throw std::runtime_error("not yet implemented");
}

PinState GPIO_Pigpio::read() const {
    CORE_ERROR("Not Yet Implemented");
    throw std::runtime_error("not yet implemented");
}

bool GPIO_Pigpio::write(PinState state) {
    CORE_ERROR("Not Yet Implemented");
    throw std::runtime_error("not yet implemented");
}

bool GPIO_Pigpio::toggle() {
    CORE_ERROR("Not Yet Implemented");
    throw std::runtime_error("not yet implemented");
}

bool GPIO_Pigpio::setPullUp(bool enabled) {
    CORE_ERROR("Not Yet Implemented");
    throw std::runtime_error("not yet implemented");
}

bool GPIO_Pigpio::setPullDown(bool enabled) {
    CORE_ERROR("Not Yet Implemented");
    throw std::runtime_error("not yet implemented");
}

int GPIO_Pigpio::getPin() const {
    CORE_ERROR("Not Yet Implemented");
    throw std::runtime_error("not yet implemented");
}
