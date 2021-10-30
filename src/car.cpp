#include <iostream>
#include <string>

class Car {
    std::string color;
    std::string mark;
    int carNumber;
    double power;
    int doorNumber;
    int year;
    bool sport;
    bool automaticCar;
    std::string creator;

    public:
        Car(std::string color, std::string mark, int carNumber, double power, int doorNumber, int year, bool sport, bool automaticCar) {
            this->color = color;
            this->mark = mark;
            this->carNumber = carNumber;
            this->power = power;
            this->doorNumber = doorNumber;
            this->year = year;
            this->sport = sport;
            this->automaticCar = automaticCar;
        }

        void setCreator(std::string creatorName) {
            this->creator = std::move(creatorName);
        }

        void printCar() {
            std::cout << "Added by: " <<  this->creator  << " -> Car: color = " << color << " mark = " << mark << " carNumber = " << carNumber << " power " << power << " doorNumber " << doorNumber << " year = " << year << " sport = " << sport << " automaticCar = " << automaticCar << std::endl;
        }
};