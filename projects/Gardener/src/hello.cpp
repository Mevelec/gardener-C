#include <stdio.h>
#include <LoggerAPI.h>
#include <InstrumentorAPI.h>

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

int main(void) {
   puts("Hello, world!");

   testLogger();

   PROFILE_BEGIN_SESSION("test", "/workspace/restult.txt");
   testInstrumentor();
   PROFILE_END_SESSION();

   return 0;
}

