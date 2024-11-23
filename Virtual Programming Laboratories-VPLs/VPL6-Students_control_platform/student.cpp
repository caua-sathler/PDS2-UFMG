#include "student.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>

Student::Student(std::string name, int id, std::vector<int> grades) {
    this->name = name;
    this->id = id;
    this->grades = grades;
}

void Student::average_grade(std::vector<int> grades) {
    int sum = 0;
    int num_elements = 0;
    for(const auto& i : grades) {
        sum += grades[i];
        num_elements++;
    }

    float average = sum/num_elements;
    std::cout << std::setprecision(2) << std::fixed << average << std::endl;
}

void Student::min_max_grade(std::vector<int> grades) {
    const auto min = std::min_element(begin(grades), end(grades));
    const auto max = std::max_element(begin(grades), end(grades));

    std::cout << *min << " " << *max << std::endl;
}





