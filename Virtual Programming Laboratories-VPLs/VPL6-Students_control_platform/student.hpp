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
    void average_grade(std::vector<int> grades);
    void min_max_grade(std::vector<int> grades);
    
};


#endif