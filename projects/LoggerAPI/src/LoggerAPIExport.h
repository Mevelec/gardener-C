#pragma once
#ifdef __GNUC__
    #define LOGGER_API __attribute__((visibility("default")))
#else
    #ifdef _WIN32
        #ifdef LOGGER_EXPORTS
            #define LOGGER_API __declspec(dllexport)
        #else
            #define LOGGER_API __declspec(dllimport)
        #endif
    #else
        #define LOGGER_API
    #endif
#endif