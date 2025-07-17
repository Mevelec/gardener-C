#include "IGPIO.h"

class GPIO_Pigpio : public IGPIO {
public:
    GPIO_Pigpio(int pinNumber);
    ~GPIO_Pigpio() override;

    bool setMode(PinMode mode) override;
    PinState read() const override;
    bool write(PinState state) override;
    bool toggle() override;
    bool setPullUp(bool enabled) override;
    bool setPullDown(bool enabled) override;
    int getPin() const override;

private:

    int pinNumber_;
    PinMode mode_;
    mutable bool initialized_ = false;
};


