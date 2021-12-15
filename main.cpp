#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <thread>
#include <mutex>
#include "car.cpp"
#include "driver.cpp"
#include "lock.cpp"
#define DATABASE_NAME "db.txt"

std::mutex m;

std::map<int, std::shared_ptr<Car>> carsArray;
std::map<int, std::unique_ptr<Driver>> carDriver;

int driverAssignedTo;

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
        std::shared_ptr<Car> carData = std::make_shared<Car>(color, mark, carNumber, power, doorNumber, year, sport, automaticCar);
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

void insertCar(Car car) {
    int carId = (--carsArray.end())->first;
    std::ofstream database(DATABASE_NAME);
    carsArray.insert(std::make_pair((++carId), std::make_shared<Car>(car)));

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

void assignDriver(int carId) 
{
    Lock flag(&m);

    if (carsArray.find(carId) == carsArray.end()) 
    {
        std::cout << "Car Id not found" << std::endl;
        return;
    }

    std::unique_ptr<Driver> vipDriver = std::make_unique<Driver>("Foo", "Bar", 50);

    // If the driver is already assigned to another car we transfer it
    if (driverAssignedTo) 
    {
        carDriver[carId] = std::move(carDriver[driverAssignedTo]);
    } 
    else 
    {
        carDriver[carId] = std::move(vipDriver);
    }

    driverAssignedTo = carId;
    std::cout << "Driver is assigned" << std::endl;
}

void showDriverDetails() 
{
    Lock flag(&m);
    if (driverAssignedTo) 
    {
        std::cout << (*carDriver[driverAssignedTo]).name << " " << (*carDriver[driverAssignedTo]).surname << " is driving car ";
        std::cout << driverAssignedTo << std::endl;
    } 
    else 
    {
        std::cout << "The driver is not assigned to any car" << std::endl;
    }
}

int main()
{
    std::cout << "Assignment operator:" << std::endl;
    Car a;
    Car b;
    Car c;
    Car d("Yellow", "BMW", "B-12-SSM", 6000, 3, 2019, 1, 0);
    
    std::cout << "Cars before assignment:" << std::endl;
    std::cout << a << b << c << d;

    a = b = c = d;
    std::cout << std::endl << "Cars after assignment:" << std::endl;
    std::cout << a << b << c << d;

    std::cout << std::endl << "Assignment to self:" << std::endl;
    d = std::move(d);

    readFromDatabase();
    
    // Before unique_ptr 

    std::thread t0(showDriverDetails);

    std::thread t1(assignDriver, 1);
    std::thread t2(showDriverDetails);
    
    std::thread t3(assignDriver, 3);

    // this throws a segmentation fault as we moved the unique_ptr driver to another car
    // std::cout << (*carDriver[1]).name << std::endl; 

    std::thread t4(showDriverDetails);

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // After unique_ptr

    std::string color;
    std::string mark;
    std::string carNumber;
    double power;
    int doorNumber;
    int year;
    bool sport;
    bool automaticCar;
    
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

                        Car car(color, mark, carNumber, power, doorNumber, year, sport, automaticCar);

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

                        Car car(color, mark, carNumber, power, doorNumber, year);

                        insertCar(car);
                    }
                    else 
                    {
                        Car car;
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
                    
                    std::shared_ptr<Car> newCar = carsArray[carId];
                    std::cout << "New car shared pointer use count: " << newCar.use_count() << std::endl;
                    //Car newCar(*carsArray[carId]);
                    std::cout << "Your clone:" << std::endl;
                    newCar->printVehicle();
                    insertCar(*newCar);
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
                    
                    std::shared_ptr<Car> searchSomething = carsArray[searchCarId];
                    searchSomething->printVehicle();
                    std::shared_ptr<Car> searchCar = std::move(searchSomething);
                    searchCar->printVehicle(true);
                }
                break;
            }
        }
    } while (option != Exit);

    return 0;
}