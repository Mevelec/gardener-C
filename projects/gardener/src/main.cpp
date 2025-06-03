#include "pch.h"

#include "core/GPIOController/GPIOController.h"
#include "core/GPIOController/GPIOControllerMock.h"
#include "core/GPIOController/GPIOControllerImpl.h"
#include "core/calendar/event/event.h"

static GPIOController* CreateGPIOController() {
    return new GPIOControllerMock();
}


time_t createTime(int year, int month, int day) {
    struct tm timeStruct = {};
    timeStruct.tm_year = year - 1900; // years since 1900
    timeStruct.tm_mon = month - 1;     // months since January (0-11)
    timeStruct.tm_mday = day;           // day of the month (1-31)
    return mktime(&timeStruct);
}

int main(int argc, char* argv[]) {
    Gardener::Log::Init();
    GA_PROFILE_BEGIN_SESSION("Startup", "profiling/Startup.json");
    GA_PROFILE_FUNCTION();

    
    Calendar::Event dailyEvent("Daily Meeting", createTime(2023, 10, 1), createTime(2023, 10, 4), Calendar::Recurence::DAILY);
    std::set<time_t> occurrences = dailyEvent.getNextOccurrences(5, createTime(2023, 10, 1));
    for (auto &&i : occurrences)
    {
        GA_CORE_DEBUG(i);
    }
    
    GPIOController* gpioController = CreateGPIOController();
    {
        GA_PROFILE_SCOPE("test sope");
        for (size_t i = 0; i < 1000000000; i++)
        {
            /* code */
        }
        
    }

    // Simuler l'activation et la désactivation des modules
    gpioController->activate(Module::LIGHTING);
    gpioController->deactivate(Module::LIGHTING);
    
    gpioController->activate(Module::VALVE);
    gpioController->deactivate(Module::VALVE);

    gpioController->activate(Module::PUMP);
    gpioController->deactivate(Module::PUMP);

    GA_PROFILE_END_SESSION();

    delete gpioController; // Libérer la mémoire
    return 0;
}