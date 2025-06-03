#pragma once

#include <string>

namespace Calendar {
    enum class Recurence { NONE, DAILY, WEEKLY, MONTHLY };
            
    static std::string RecurenceToString(const Recurence& recurence) {
        switch (recurence) {
            case Recurence::DAILY: return "DAILY";
            case Recurence::WEEKLY: return "WEEKLY";
            case Recurence::MONTHLY: return "MONTHLY";
            default: return "NONE";
        }
    }
};