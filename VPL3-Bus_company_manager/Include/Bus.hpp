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
    std::string get_plate() const;
    int get_max_capacity() const;
    int get_current_occupancy() const;
    void add_passengers(int num_people);
    void subtract_passengers(int num_people);
    void transfer_passengers(Bus *other_bus, int num_people);
};

#endif