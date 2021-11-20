#include <iostream>
#include <string>

class Vehicle
{
    public: 
        std::string color;
        std::string mark;
        std::string vehicleNumber;

        Vehicle(const Vehicle& vehicle) 
        {
            color = std::move(vehicle.color);
            mark = std::move(vehicle.mark);
            vehicleNumber = std::move(vehicle.vehicleNumber);

            std::cout << "Vehicle base copy-constructor called!" << std::endl;
        }

        virtual void printVehicle() = 0;

        Vehicle() : color("Red"), mark("Toyota"), vehicleNumber("B-00-CAR") {}
};