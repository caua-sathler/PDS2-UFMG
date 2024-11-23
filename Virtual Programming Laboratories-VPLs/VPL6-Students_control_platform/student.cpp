#include "student.hpp"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>

Student::Student(std::string name, int id, std::vector<int> grades) {
    this->name = name;
    this->id = id;
    this->grades = grades;
}

float Student::average_grade(std::vector<int> grades) {
    int sum = 0;
    int num_elements = 0;
    for(int i : grades) {
        sum += grades[i];
        num_elements++;
    }

    float average = sum/num_elements;
    return average;
}

int Student::min_max_grade(std::vector<int> grades) {
    
}


