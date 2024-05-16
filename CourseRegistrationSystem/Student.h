#ifndef Student_H
#define Student_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student : public User { //Take both protected and public variables
    vector<string> regularCourses;
    vector<string> specialCourses;
public:
    Student(string name) : User(name) {}

    void displayInfo() const override {
        cout << "Student Name: " << userName << endl;
        cout << "Regular Courses: ";
        for (const auto& course : regularCourses) { //The variable course is belongs to regularCourses
            cout << course << " ";
        }
        cout << endl;
        cout << "Special Courses: ";
        for (const auto& course : specialCourses) { //The variable course is belongs to specialCourses
            cout << course << " ";
        }
        cout << endl;
    }

    void registerRegularCourse(const string& course) { //Stores the chosen course regularCourses vector
        regularCourses.push_back(course);
    }

    void registerSpecialCourse(const string& course) { //Stores the chosen course specialCourses vector
        specialCourses.push_back(course);
    }
};

#endif