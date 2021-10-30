#include <iostream>
#include <string>

class Car {
    std::string color;
    std::string mark;
    std::string carNumber;
    double power;
    int doorNumber;
    int year;
    bool sport;
    bool automaticCar;
    std::string creator;

    public:

        Car() : color("red"), mark("Toyota"), carNumber("B 00 CAR"), power(90), doorNumber(4), year(1990), sport(0), automaticCar(0) {}

        Car(const Car& car) {
            color = std::move(car.color);
            mark = std::move(car.mark);
            carNumber = std::move(car.carNumber);
            power = car.power;
            doorNumber = car.doorNumber;
            year = car.year;
            sport = car.sport;
            automaticCar = car.automaticCar;
        }

        Car(std::string color, std::string mark, std::string carNumber, double power, int doorNumber, int year, bool sport = 0, bool automaticCar = 0) {
            this->color = std::move(color);
            this->mark = std::move(mark);
            this->carNumber = std::move(carNumber);
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