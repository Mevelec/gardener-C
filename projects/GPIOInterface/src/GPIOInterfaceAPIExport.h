#pragma once

#ifdef __GNUC__
    #define GPIO_INTERFACE __attribute__((visibility("default")))
#else
    #ifdef _WIN32
        #ifdef GPIO_INTERFACE_EXPORTS
            #define GPIO_INTERFACE __declspec(dllexport)
        #else
            #define GPIO_INTERFACE __declspec(dllimport)
        #endif
    #else
        #define GPIO_INTERFACE
    #endif
#endif