#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;
    std::vector<int> grades;

public:
    Student(std::string name, int id, std::vector<int> grades);
    float average_grade(std::vector<int> grades);
    int min_max_grade(std::vector<int> grades);
    
};


#endif