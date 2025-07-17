#include <unordered_map>
#include "GPIO_Mock.h"

GPIO_Mock::GPIO_Mock(int pinNumber) : pinNumber_(pinNumber), state_(PinState::LOW), mode_(PinMode::INPUT)
{
    // initialize state if needed
}

bool GPIO_Mock::setMode(PinMode mode)
{
    mode_ = mode;
    return true;
}

PinState GPIO_Mock::read() const
{
    auto it = pinStates.find(pinNumber_);
    if (it != pinStates.end())
    {
        return it->second;
    }
    return PinState::LOW;
}

bool GPIO_Mock::write(PinState state)
{
    pinStates[pinNumber_] = state;
    return true;
}

bool GPIO_Mock::toggle()
{
    auto it = pinStates.find(pinNumber_);
    if (it != pinStates.end())
    {
        it->second = (it->second == PinState::HIGH) ? PinState::LOW : PinState::HIGH;
    }
    else
    {
        pinStates[pinNumber_] = PinState::HIGH;
    }
    return true;
}

int GPIO_Mock::getPin() const
{
    return pinNumber_;
}