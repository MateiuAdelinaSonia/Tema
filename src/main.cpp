#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "car.cpp"
#define CURENT_USER "admin"
#define DATABASE_NAME "db.txt"

std::map<int, Car*> carsArray;

void readFromDatabase() 
{
    std::ifstream database(DATABASE_NAME);
    int carId;
    std::string color;
    std::string mark;
    std::string carNumber;
    double power;
    int doorNumber;
    int year;
    bool sport;
    bool automaticCar;

    while (database >> carId >> color >> mark >> carNumber >> power >> doorNumber >> year >> sport >> automaticCar) 
    {
        Car *carData = new Car(color, mark, carNumber, power, doorNumber, year, sport, automaticCar);
        carsArray.insert(std::make_pair(carId, carData));
    }
}

int main()
{
    readFromDatabase();

    carsArray[1]->setCreator(CURENT_USER);
    carsArray[1]->printCar();

    return 0;
}