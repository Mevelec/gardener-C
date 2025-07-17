#include "IGPIO.h"
#include "pigpio/GPIO_Pigpio.h"
#include "mock/GPIO_Mock.h"
#include <memory>
#include "GPIOInterfaceAPIExport.h"

enum class GPIOImplementation {
    Real,
    Mock
};

class GPIO_INTERFACE GPIOFactory {
public:
    static std::shared_ptr<IGPIO> create(int pinNumber, GPIOImplementation implType = GPIOImplementation::Real) {
        if (implType == GPIOImplementation::Mock) {
            return std::make_shared<GPIO_Mock>(pinNumber);
        }
        else if (implType == GPIOImplementation::Real) {
            return std::make_shared<GPIO_Pigpio>(pinNumber);
        }  
        else {
            throw std::invalid_argument("Unsupported GPIO implementation type");
        }
    }
};