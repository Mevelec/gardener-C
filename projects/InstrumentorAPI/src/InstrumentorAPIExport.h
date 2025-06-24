#pragma once

#ifdef __GNUC__
    #define INSTRUMENTOR_API __attribute__((visibility("default")))
#else
    #ifdef _WIN32
        #ifdef INSTRUMENTOR_EXPORTS
            #define INSTRUMENTOR_API __declspec(dllexport)
        #else
            #define INSTRUMENTOR_API __declspec(dllimport)
        #endif
    #else
        #define INSTRUMENTOR_API
    #endif
#endif