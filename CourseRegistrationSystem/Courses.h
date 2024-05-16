#ifndef Cousres_H
#define Courses_H
#include <iostream>
#include <vector>
#include <string>

class Course {
    string courseName;
public:
    Course(string name) : courseName(name) {}

    string getName() const {
        return courseName;
    }
};

#endif