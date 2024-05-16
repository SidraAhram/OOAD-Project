#ifndef FacultyAdvisor_H
#define FacultyAdvisor_h
#include <iostream>
#include <vector>
#include <string>

class FacultyAdvisor : public User {
    string department;
    vector<string> schedule;
public:
    FacultyAdvisor(string name, string dept) : User(name), department(dept) {}

    void displayInfo() const override {
        cout << "Faculty Advisor Name: " << userName << endl;
        cout << "Department: " << department << endl;
        cout << "Schedule: ";
        for (const auto& scheduleItem : schedule) { //The variable scheduleItem belongs to schedule
            cout << scheduleItem << " ";
        }
        cout << endl;
    }

    void setSchedule(const vector<string>& schedule) { //Sets schedule of current object to schedule vector
        this->schedule = schedule;
    }

    string getDepartment() const { //Returns the department of the object
        return department;
    }
};

#endif