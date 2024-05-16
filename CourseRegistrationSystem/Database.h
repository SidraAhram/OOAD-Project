#ifndef Database_H
#define Database_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include "User.h"
#include "Student.h"
#include "Schedules.h"

class Database {
private:
    vector<unique_ptr<User>> users;
    vector<Course> courses;
    unordered_map<string, vector<string>> departmentSchedules; //Stores schedules for each department

public:
    Database() {
        addDepartmentSchedule("Civil", { "Monday:\t\tCE354\t09:40 - 12:30", "\nTuesday:\tCE372\t09:40 - 12:30", "\nWednesday:\tCE352\t13:40 - 15:30","\nThursday:\tCE362\t09:40 - 12:30","\nFriday:\t\tOFF DAY!" });
        addDepartmentSchedule("Software", { "Monday:\t\tSENG226\t13:40 - 16:30", "\nTuesday:\tMATH212\t13:40 - 16:30", "\nWednesday:\tFE202\t13:40 - 15:30","\nThursday:\tOFF DAY!","\nFriday:\t\tSENG228\t09:40 - 12:30" });
        addDepartmentSchedule("Computer", { "Monday:\t\tCENG112\t08:40 - 11:30","\nTuesday:\tFE102\t13:40 - 15:30", "\nWednesday:\tPHYS102\t08:40 - 11:30", "\nThursday:\tMATH114\t08:30 - 10:30", "\nFriday:\t\tOFF DAY!" });
        addDepartmentSchedule("Industrial", { "Monday:\t\tOFF DAY!","\nTuesday:\tMATH112\t08:40 - 12:30", "\nWednesday:\tPHYS102\t13:40 - 16:30", "\nThursday:\tPHYS102\t08:40 - 10:30","\nFriday:\t\tOFF DAY!" });
    }

    void addUser(unique_ptr<User> user) { //Transferring ownership using unique_ptr
        users.push_back(move(user)); //Adds a user from user to the users collection
    }

    void addCourse(const Course& course) { //Stores the course to the courses vector
        courses.push_back(course);
    }

    void addDepartmentSchedule(const string& department, const vector<string>& schedule) { //Adds a schedule for a department
        departmentSchedules[department] = schedule; //Assigns the schedule to the specified department
    }

    vector<unique_ptr<User>>& getUsers() {
        return users;
    }

    void displayDepartmentSchedule(const string& department) const {
        auto it = departmentSchedules.find(department); //Find department's schedule
        if (it != departmentSchedules.end()) {
            cout << "Schedule for Department of " << department << " Engineering :" << endl;
            for (const auto& scheduleItem : it->second) { //Iterate over schedule items
                cout << scheduleItem << " ";
            }
            cout << endl;
        }
        else {
            cout << "Schedule not found for Department of " << department <<" Engineering."<< endl;
        }
    }
};

#endif