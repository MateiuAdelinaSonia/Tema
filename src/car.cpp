#include <iostream>
#include <string>
#include "vehicle.cpp"

class Car : public Vehicle
{
    double power;
    int doorNumber;
    int year;
    bool sport;
    bool automaticCar;
    std::string creator;

    public:

        Car() : Vehicle(), power(90), doorNumber(4), year(1990), sport(0), automaticCar(0) {}

        Car(const Car& car) 
        {
            color = std::move(car.color);
            mark = std::move(car.mark);
            vehicleNumber = std::move(car.vehicleNumber);
            power = car.power;
            doorNumber = car.doorNumber;
            year = car.year;
            sport = car.sport;
            automaticCar = car.automaticCar;
        }

        Car(std::string color, std::string mark, std::string vehicleNumber, double power, int doorNumber, int year, bool sport = 0, bool automaticCar = 0) 
        {
            this->color = std::move(color);
            this->mark = std::move(mark);
            this->vehicleNumber = std::move(vehicleNumber);
            this->power = power;
            this->doorNumber = doorNumber;
            this->year = year;
            this->sport = sport;
            this->automaticCar = automaticCar;
        }

        void setCreator(std::string creatorName) 
        {
            this->creator = std::move(creatorName);
        }

        void printVehicle() 
        {
            std::cout << "Added by: " <<  this->creator  << " -> Car: color = " << color << " mark = " << mark << " vehicleNumber = " << vehicleNumber << " power " << power << " doorNumber " << doorNumber << " year = " << year << " sport = " << sport << " automaticCar = " << automaticCar << std::endl;
        }
};