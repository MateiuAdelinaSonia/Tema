#include <iostream>
#include <string>

class Driver
{
    public: 
        std::string name;
        std::string surname;
        int age;

        Driver(std::string name, std::string surname, int age) 
        {
            this->name = std::move(name);
            this->surname = std::move(surname);
        }
};