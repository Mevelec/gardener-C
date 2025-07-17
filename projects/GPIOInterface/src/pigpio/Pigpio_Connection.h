#include <pigpiod_if2.h>
#include <LoggerAPI.h>

class Pigpio_Connection {
public:

    // Deleted copy constructor and assignment operator to prevent copies
    Pigpio_Connection(const Pigpio_Connection&) = delete;
    Pigpio_Connection& operator=(const Pigpio_Connection&) = delete;

    // Static method to access the instance
    static Pigpio_Connection& getInstance() {
        static Pigpio_Connection instance; // Guaranteed to be thread-safe in C++11 and later
        return instance;
    }

    // Example member function
    void doSomething() {
        // Implementation
    }


    const char* optHost = "localhost";
    const char* optPort = "8888";
private:
    int pi;
    // Private constructor to prevent instantiation
    Pigpio_Connection() {
        int pi = pigpio_start(optHost, optPort); /* Connect to local Pi. */
        if (pi >= 0)
        {
            CORE_INFO("Connected to pigpiod daemon at {} : {}", optHost, optPort);
        } else {
            // Handle connection error
            CORE_ERROR("Failed to connect to pigpiod daemon at {} : {}", optHost, optPort);
            throw std::runtime_error("pigpio_start failed");
        }
    }

    // Optional: define destructor if needed
    ~Pigpio_Connection() {
        pigpio_stop(0);
    }
};