#pragma once

#include "GPIOController.h"

class GPIOControllerMock : public GPIOController {
private:
    std::map<Module, bool> stateMap;

public:
    GPIOControllerMock();

    void activate(Module module) override;
    void deactivate(Module module) override;
};