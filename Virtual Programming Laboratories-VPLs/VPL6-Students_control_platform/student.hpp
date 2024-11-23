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
    std::string get_name() const;
    int get_id() const;
    const std::vector<int>& get_grades() const;
    void average_grade() const;
    void min_max_grade() const;
    void print_grades() const;
    
};


#endif