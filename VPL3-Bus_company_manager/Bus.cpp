#include "Bus.hpp"
#include <string>;
#include <iostream>;

Bus::Bus(std::string lisense_plate, int max_capacity) {
    this->lisense_plate = lisense_plate;
    this->max_capacity = max_capacity;
}

void Bus::add_passengers(int num) {
    if(num > (max_capacity - current_occupancy))
        std::cout << "ERRO : onibus lotado";
     else {
        current_occupancy =+ num;
        std::cout << "passageiros subiram com sucesso";
     }
        
    
    
}

void Bus::subtract_passengers(int num) {
    if(num > current_occupancy)
        std::cout << "ERRO : faltam passageiros";
    else {
        current_occupancy =- num;
        std::cout << "passageiros desceram com sucesso";
    }
        
}

void Bus::transfer_passengers(Bus *p, int num) {
    if(num > current_occupancy || num > (p->max_capacity - p->current_occupancy))
        std::cout << "ERRO : transferencia cancelada";
    else {
        current_occupancy =- num;
        p->current_occupancy =+ num;
        std::cout << "transferencia de passageiros efetuada";
    }
    
}

void Bus::print_status() const {
    std::cout << lisense_plate << " (" << current_occupancy << "/" 
    << max_capacity << ")" << std::endl;  
}