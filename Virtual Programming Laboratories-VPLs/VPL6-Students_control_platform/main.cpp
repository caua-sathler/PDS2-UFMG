#include "student.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <set>

#define SUCESSO 0

int main() {
    std::string name;
    int id;
    std::vector<int> grades;
    
    struct sort_students_f {
        bool operator()(const Student& a, const Student& b) const {
            return a.get_name() < b.get_name(); 
        }
    };

    std::multiset<Student, sort_students_f> student_bunker;
    
    while(true) {
        std::cin >> name;
        if(name == "END")
            break;

        std::cin >> id;
        
        int grade;
        while (true) {
            std::cin >> grade;
            if (grade == -1) break;
            grades.push_back(grade);
        }

        Student student(name, id, grades);
        student_bunker.insert(student);
        grades.clear();
    }

    for(auto const& student : student_bunker) {
        std::cout << student.get_id() << " " << student.get_name() << " ";
        student.print_grades();
        student.average_grade();
        student.min_max_grade();
    }

return SUCESSO;
}