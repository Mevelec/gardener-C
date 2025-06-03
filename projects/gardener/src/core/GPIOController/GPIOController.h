#pragma once

#include "pch.h"

#include <iostream>
#include <map>
#include <string>

#include "module/module.h"

class GPIOController {
public:
    virtual ~GPIOController() {}

    virtual void activate(Module module) = 0;
    virtual void deactivate(Module module) = 0;
};
