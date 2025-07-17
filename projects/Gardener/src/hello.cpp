#include <stdio.h>
#include <LoggerAPI.h>
#include <InstrumentorAPI.h>
#include <factory/GPIO_Factory.h>

void testLogger(){
   LoggerAPI::Logger::Init();

   CORE_TRACE("CORE_TRACE");
   CORE_INFO("CORE_INFO");
   CORE_WARN("CORE_WARN");
   CORE_ERROR("CORE_ERROR");
   CORE_FATAL("CORE_FATAL");

   TRACE("RACE");
   INFO("INFO");
   WARN("WARN");
   ERROR("ERROR");
   FATAL("FATAL");
}

void testInstrumentor() {
   PROFILE_FUNCTION()
   for (int i = 0; i < 100000; i++)
   {
      /* code */
   }
}

void testGPIO() {
   PROFILE_FUNCTION()
   GPIOFactory gpioFactory;
   auto gpio_1 = gpioFactory.create(0, GPIOImplementation::Mock);
   if (gpio_1) { 
      gpio_1->setMode(PinMode::INPUT);
      PinState state = gpio_1->read();
      CORE_INFO("Mock Pin state: {}", state == PinState::HIGH ? "HIGH" : "LOW");
   } else {
      CORE_ERROR("Failed to create Mock GPIO instance");
   }


   auto gpio_2 = gpioFactory.create(0, GPIOImplementation::Real);
   if (gpio_2) { 
      gpio_2->setMode(PinMode::INPUT);
      PinState state = gpio_2->read();
      CORE_INFO("Real Pin state: {}", state == PinState::HIGH ? "HIGH" : "LOW");
   } else {
      CORE_ERROR("Failed to create Real GPIO instance");
   }
}

int main(void) {
   puts("Hello, world!");

   testLogger();

   PROFILE_BEGIN_SESSION("test", "/workspace/restult.txt");
   testInstrumentor();
   PROFILE_END_SESSION();
   
   PROFILE_BEGIN_SESSION("testGPIO", "/workspace/testGPIO.txt");
   testGPIO();
   PROFILE_END_SESSION();

   return 0;
}

