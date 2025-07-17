#include <unordered_map>
#include "IGPIO.h"

class GPIO_Mock : public IGPIO
{
public:
    GPIO_Mock(int pinNumber);
    ~GPIO_Mock() override = default;

    bool setMode(PinMode mode) override;
    PinState read() const override;
    bool write(PinState state) override;
    bool toggle() override;
    bool setPullUp(bool enabled) override { return true; }
    bool setPullDown(bool enabled) override { return true; }
    int getPin() const override;

private:
    int pinNumber_;
    PinState state_;
    PinMode mode_;
    static std::unordered_map<int, PinState> pinStates; // Shared across instances
};

std::unordered_map<int, PinState> GPIO_Mock::pinStates;