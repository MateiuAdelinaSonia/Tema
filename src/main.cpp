#include <iostream>
#include <string>
#include "car.cpp"

int main()
{
    std::string currentUser = "admin";
    std::string color;
    std::string mark;
    int carNumber;
    double power;
    int doorNumber;
    int year;
    bool sport;
    bool automaticCar;

    std::cout << "Car color:" << std::endl;
    std::cin >> color;
    std::cout << "Car mark:" << std::endl;
    std::cin >> mark;
    std::cout << "Car number:" << std::endl;
    std::cin >> carNumber;
    std::cout << "Car power:" << std::endl;
    std::cin >> power;
    std::cout << "Car doorNumber:" << std::endl;
    std::cin >> doorNumber;
    std::cout << "Car year:" << std::endl;
    std::cin >> year;
    std::cout << "Sport car:" << std::endl;
    std::cin >> sport;
    std::cout << "Automatic car:" << std::endl;
    std::cin >> automaticCar;

    Car *car1 = new Car(color, mark, carNumber, power, doorNumber, year, sport, automaticCar);
    car1->setCreator(currentUser);
    car1->printCar();

    return 0;
}