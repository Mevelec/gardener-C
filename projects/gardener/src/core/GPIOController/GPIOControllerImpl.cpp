#include "GPIOControllerImpl.h"
#include <wiringPi.h>
#include "pch.h"


GPIOControllerImpl::GPIOControllerImpl() {
    // Initialiser wiringPi
    wiringPiSetup();
    // Configurer les broches GPIO en sortie
    pinMode(0, OUTPUT); // LIGHTING
    pinMode(1, OUTPUT); // VALVE
    pinMode(2, OUTPUT); // PUMP
}

GPIOControllerImpl::~GPIOControllerImpl() {}

void GPIOControllerImpl::activate(Module module) {
    int pin = getPinKey(module);
    digitalWrite(pin, HIGH);
    GA_CORE_TRACE("Activated module: " + ModuleToString(module));
}

void GPIOControllerImpl::deactivate(Module module) {
    int pin = getPinKey(module);
    digitalWrite(pin, LOW);
    GA_CORE_TRACE("Deactivated module: " + ModuleToString(module));
}

int GPIOControllerImpl::getPinKey(Module module) {
    switch (module) {
        case Module::LIGHTING: return 0; // GPIO 0
        case Module::VALVE: return 1;     // GPIO 1
        case Module::PUMP: return 2;      // GPIO 2
        default: return -1;  // Invalid
    }
}