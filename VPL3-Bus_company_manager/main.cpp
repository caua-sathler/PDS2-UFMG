#include "Bus.hpp"
#include "Company.hpp"

#include <string>
#include <iostream>

int main() {
    Company company;

    char command;
    int max_capacity;
    int num_people;
    std::string plate_1;
    std::string plate_2;

    while(1) {
        std::cin >> command;
    
        if(command == 'C') {
            std::cin >> plate_1;
            std::cin >> max_capacity;
            if(company.add_bus(plate_1, max_capacity) == nullptr)
                std::cout << "ERRO : onibus repetido" << std::endl;
            else {
                std::cout << "novo onibus cadastrado" << std::endl;
            }
        continue;
        }

        if(command == 'S') {
            std::cin >> plate_1;
            std::cin >> num_people;
            Bus* bus = company.bus_search(plate_1);
    
            if(bus == nullptr)
                std::cout << "ERRO : onibus inexistente" << std::endl;
            else 
            {
                bus->add_passengers(num_people);
            }
        continue;
        }

        if(command == 'D') {
            std::cin >> plate_1;
            std::cin >> num_people;
            Bus* bus = company.bus_search(plate_1);

            if(bus == nullptr)
                std::cout << "ERRO : onibus inexistente" << std::endl;
            else {
                bus->subtract_passengers(num_people);
            }
        continue;
        }

        if(command == 'T') {
            std::cin >> plate_1;
            std::cin >> plate_2;
            std::cin >> num_people;
            Bus* bus1 = company.bus_search(plate_1);
            Bus* bus2 = company.bus_search(plate_2);

            if(bus1 == nullptr || bus2 == nullptr)
                std::cout << "ERRO: onibus inexistente";
            else {
                bus1->transfer_passengers(bus2, num_people);
            }
        continue;
        }

        if(command == 'I') {
            company.print_bus_status();
        continue;
        }

        if(command == 'F') {
            break;
        }

    }

    return 0;
}