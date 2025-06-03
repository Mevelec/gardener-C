#pragma once

#include "GPIOController.h"

class GPIOControllerImpl : public GPIOController {
public:
    GPIOControllerImpl();
    ~GPIOControllerImpl();

    void activate(Module module) override;
    void deactivate(Module module) override;

private:
    int getPinKey(Module module);
};
