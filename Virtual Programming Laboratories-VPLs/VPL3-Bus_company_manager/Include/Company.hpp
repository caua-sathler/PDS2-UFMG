#ifndef COMPANY_H
#define COMPANY_H

#include "Bus.hpp"
#include <iostream>
#include <string>

class Company {
private:
    int num_buses;
    Bus* buses[20];

public:
    Company();
    Bus* add_bus(std::string lisense_plate, int max_capacity);
    Bus* bus_search(std::string lisense_plate) const;
    void print_bus_status() const;
    ~Company();
};

#endif