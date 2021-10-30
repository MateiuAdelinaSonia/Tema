#include <iostream>
#include <string>

class Vehicle
{
    public: 
        std::string color;
        std::string mark;
        std::string vehicleNumber;

    public:
        virtual void printVehicle() = 0;

        Vehicle() : color("red"), mark("Toyota"), vehicleNumber("B 00 CAR") {}
};