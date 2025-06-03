#pragma once

#include <string>

// Enumeration for controlling module types
enum class Module {
    LIGHTING,
    VALVE,
    PUMP
};
static std::string ModuleToString(const Module& module) {
    switch (module) {
        case Module::LIGHTING: return "LIGHTING";
        case Module::VALVE: return "VALVE";
        case Module::PUMP: return "PUMP";
        default: return "UNKNOWN";
    }
}