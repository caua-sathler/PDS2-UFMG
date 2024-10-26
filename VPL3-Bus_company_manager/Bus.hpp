#ifndef BUS_H
#define BUS_H

#include <string>

class Bus{
private:
    std::string lisense_plate;
    int max_capacity;
    int current_occupancy;     

public:
    Bus(std::string lisence_plate, int max_capacity);
    void add_passengers(int x);
    void subtract_passengers(int y);
    void transfer_passengers(Bus *p, int z);
    void print_status() const;

};




#endif