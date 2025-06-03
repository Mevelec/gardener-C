#include "GPIOControllerMock.h"

GPIOControllerMock::GPIOControllerMock() {
    stateMap[Module::LIGHTING] = false;
    stateMap[Module::VALVE] = false;
    stateMap[Module::PUMP] = false;
}

void GPIOControllerMock::activate(Module module) {
    stateMap[module] = true;
    GA_CORE_TRACE("Activated module: " + ModuleToString(module));
}

void GPIOControllerMock::deactivate(Module module) {
    stateMap[module] = false;
    GA_CORE_TRACE("Deactivated module: " + ModuleToString(module));
}