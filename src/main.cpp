#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "car.cpp"
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

void MainScreen()
{
    std::cout << std::endl << "Welcome!" << std::endl << std::endl;
}

void Menu()
{    
    std::cout << "Your option:" << std::endl << std::endl << "1. AddCar" << std::endl << "2. ShowCars" << std::endl << "3. CloneCar" << std::endl << "4. SearchCar" << std::endl << "5. Exit" << std::endl << std::endl;
}

void insertCar(Car *car) {
    int carId = (--carsArray.end())->first;
    std::ofstream database(DATABASE_NAME);
    carsArray.insert(std::make_pair((++carId), car));

    for (const auto &carElement : carsArray)
    {
        database << carElement.first << " " << *carElement.second;
    }

    database.close();
}

void showCars() 
{
    std::cout << "ID" << " Color" << " Mark" << " CarNumber" << " Power" << " DoorNumber" << " Year" << " Sport" << " AutomaticCar" << std::endl << std::endl;
    for (const auto &carElement : carsArray)
    {
        std::cout << carElement.first << " " << *carElement.second;
    }
}

int main()
{
    readFromDatabase();

    std::string color;
    std::string mark;
    std::string carNumber;
    double power;
    int doorNumber;
    int year;
    bool sport;
    bool automaticCar;

    Car *car1 = new Car(color, mark, carNumber, power, doorNumber, year, sport, automaticCar);
    
    int option;

    const int AddCar = 1;
    const int ShowCars = 2;
    const int CloneCar = 3;
    const int SearchCar = 4;
    const int Exit = 5;
    
    do
    {
        MainScreen();
        Menu(); 
        std::cout << "Your option: " << std::endl;
        std::cin >> option;
        
        while (option < AddCar || option > Exit)
        {
            std::cout << "Invalid option!" << std::endl;
            std::cout << "Your option:" << std::endl;
            std::cin >> option;
        }
         
        if (option != Exit)
        {
            switch (option)
            {
                case AddCar:
                {
                    int itemNumber;

                    std::cout << "Number of items (0 or 6 or 8):" << std::endl;
                    std::cin >> itemNumber;

                    if (itemNumber == 8)
                    {
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

                        Car *car = new Car(color, mark, carNumber, power, doorNumber, year, sport, automaticCar);

                        insertCar(car);
                    }
                    else if (itemNumber == 6)
                    {
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

                        Car *car = new Car(color, mark, carNumber, power, doorNumber, year);

                        insertCar(car);
                    }
                    else 
                    {
                        Car *car = new Car();

                        insertCar(car);
                    }
                }
                break;
                           
                case ShowCars:
                {
                    showCars();
                }
                break;

                case CloneCar:
                {
                    std::cout << "Cars in database:" << std::endl;
                    showCars();

                    int carId;
                    std::cout << "Car ID:" << std::endl;
                    std::cin >> carId;
                    if (carsArray.find(carId) == carsArray.end())
                    {
                        std::cout << "ID doesn't exist!" << std::endl;
                        break;
                    }
                    
                    Car newCar(*carsArray[carId]);
                    std::cout << "Your clone:" << std::endl;
                    newCar.printVehicle();
                    insertCar(&newCar);
                }
                break;
                
                case SearchCar:
                {
                    int searchCarId;
                    std::cout << "Car ID:" << std::endl;
                    std::cin >> searchCarId;
                    if (carsArray.find(searchCarId) == carsArray.end())
                    {
                        std::cout << "ID doesn't exist!" << std::endl;
                        break;
                    }
                    
                    Car searchSomething = *carsArray[searchCarId];
                    Car searchCar = std::move(searchSomething);
                    searchSomething.printVehicle();
                    searchCar.printVehicle(true);
                }
                break;
            }
        }
    } while (option != Exit);

    return 0;
}