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

std::string Student::get_name() const {
    return name;
}

int Student::get_id() const {
    return id;
}

const std::vector<int>& Student::get_grades() const {
    return grades;
}

void Student::average_grade() const {
    int sum = std::accumulate(grades.begin(), grades.end(), 0);
    float average = static_cast<float>(sum) / grades.size();
    std::cout << std::setprecision(2) << std::fixed << average << " ";
}

void Student::min_max_grade() const {
    auto[min, max] = std::minmax_element(grades.begin(), grades.end());
    std::cout << *max << " " << *min << std::endl;
}

void Student::print_grades() const {
    for (size_t i = 0; i < grades.size(); ++i) {
        std::cout << grades[i];
        if (i < grades.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}





