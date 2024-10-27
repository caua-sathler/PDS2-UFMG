#include "Bus.hpp"
#include "Company.hpp"
#include <iostream>
#include <string>

Company::Company(){
    this->num_buses = 0;
    for(int i = 0; i < 20; i++)
    this->buses[i] = nullptr;
}

Bus* Company::add_bus(std::string lisense_plate, int max_capacity){
    if(bus_search(lisense_plate) != nullptr)
        return nullptr;
    else {
        for(int i = 0; i < 20; i++){
            if(buses[i] == nullptr){
                buses[i] = new Bus(lisense_plate, max_capacity);
                num_buses++;
                return buses[i];
            }
        }
    }
    

}

Bus* Company::bus_search(std::string lisense_plate) const{
        if(num_buses == 0) 
            return nullptr;
        else {
            for(int i = 0; i < num_buses; i++){
                if(buses[i]->get_plate() == lisense_plate)
                    return buses[i];
            } 
            
        } 
        return nullptr;
    }

void Company::print_bus_status() const {
    for(int i = 0; i < num_buses; i++){
        std::cout << buses[i]->get_plate() << " (" << buses[i]->get_current_occupancy()
        << "/" << buses[i]->get_max_capacity() << ") " << std::endl;
    }

}

Company::~Company(){
    for(int i = 0; i < num_buses; i++){
        delete buses[i];
    }
}