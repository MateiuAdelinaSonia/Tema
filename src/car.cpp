#include <iostream>
#include <string>
#include "vehicle.cpp"
#define CURENT_USER "admin"

class Car : public Vehicle
{
    public: 
        double power;
        int doorNumber;
        int year;
        bool sport;
        bool automaticCar;
        std::string *creator = new std::string(CURENT_USER);

        Car() : Vehicle(), power(90), doorNumber(4), year(1990), sport(0), automaticCar(0) {}

        Car(Car&& source) : creator { source.creator }
        {
            std::cout << "Move constructor called!" << std::endl;
            source.creator = nullptr;
        }

        // Disable Copy Assingment Operator for Car
        Car& operator=(const Car&) = delete;

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

        void printVehicle() 
        {
            if (this->creator == nullptr)
            {
                std::cout << "Added by: NULL "  << " -> Car: color = " << color << " mark = " << mark << " vehicleNumber = " << vehicleNumber << " power " << power << " doorNumber " << doorNumber << " year = " << year << " sport = " << sport << " automaticCar = " << automaticCar << std::endl;
            } 
            else 
            {
                std::cout << "Added by: " <<  *this->creator  << " -> Car: color = " << color << " mark = " << mark << " vehicleNumber = " << vehicleNumber << " power " << power << " doorNumber " << doorNumber << " year = " << year << " sport = " << sport << " automaticCar = " << automaticCar << std::endl;
            }
        }

        void printVehicle(bool partial) 
        {   
            if (partial == true) 
            {
                std::cout << "vehicleNumber = " << vehicleNumber << std::endl;
            } 
            else 
            {
                this->printVehicle();
            }
        }

        ~Car()
        {
            delete creator;
            std::cout << "Destructor called!" << std::endl;
        }
};

std::ostream& operator<<(std::ostream& op, const Car& obj) 
{
    return op << obj.color << " " << obj.mark << " " << obj.vehicleNumber << " " << obj.power << " " << obj.doorNumber << " " << obj.year << " " << obj.sport << " " << obj.automaticCar << std::endl;
} 