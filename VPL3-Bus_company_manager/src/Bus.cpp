#include "Bus.hpp"
#include <string>
#include <iostream>

Bus::Bus(std::string lisense_plate, int max_capacity) {
    this->lisense_plate = lisense_plate;
    this->max_capacity = max_capacity;
    this->current_occupancy = 0;
}

std::string Bus::get_plate() const {
    return lisense_plate;
}

int Bus::get_max_capacity() const {
    return max_capacity;
}

int Bus::get_current_occupancy() const { 
    return current_occupancy;
}

void Bus::add_passengers(int num) {
    if(current_occupancy + num > max_capacity)
        std::cout << "ERRO : onibus lotado" << std::endl;
     else {
        current_occupancy = current_occupancy + num;
        std::cout << "passageiros subiram com sucesso" << std::endl;
     }   
}

void Bus::subtract_passengers(int num) {
    if((current_occupancy - num) < 0)
        std::cout << "ERRO : faltam passageiros" << std::endl;
    else {
        current_occupancy = current_occupancy - num;
        std::cout << "passageiros desceram com sucesso" << std::endl;
    }
        
}

void Bus::transfer_passengers(Bus *p, int num) {
    if((current_occupancy - num) < 0 || (p->current_occupancy + num) > p->max_capacity)
        std::cout << "ERRO : transferencia cancelada" << std::endl;
    else {
        current_occupancy = current_occupancy - num;
        p->current_occupancy = p->current_occupancy + num;
        std::cout << "transferencia de passageiros efetuada" << std::endl;
    }
    
}
