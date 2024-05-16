#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include "User.h"
#include "Student.h"
#include "FacultyAdvisor.h"
#include "Courses.h"
#include "Schedules.h"
#include "Database.h"
using namespace std;

int main() {
    Database database;

    cout << "\nWelcome to the User Registration System!" << endl;
    cout << "\nChoose your user type";
    cout << " (1 for Student";
    cout << " and 2 for Faculty Advisor) : ";

    int userTypeChoice;
    cin >> userTypeChoice;
    string userName;

    switch (userTypeChoice) {
    case 1: {
        cout << "Enter student name : ";
        cin.ignore();
        getline(cin, userName);
        database.addUser(make_unique<Student>(userName));
        Student* student = dynamic_cast<Student*>(database.getUsers().back().get());
        if (student) {
            cout << "Choose course type ";
            cout << "(1 for Regular Courses";
            cout << " and 2 for Special Courses) : ";
            int courseType;
            cin >> courseType;
            if (courseType == 1) {
                cout << "Available Regular Courses:\n";
                cout << "\t\t1. Math\n";
                cout << "\t\t2. Biology\n";
                cout << "\t\t3. Chemistry\n";
                cout << "\t\t4. English Literature\n";
            }
            else if (courseType == 2) {
                cout << "Available Special Courses:\n";
                cout << "\t\t1. OOP : Practical course\n";
                cout << "\t\t2. Physics : Lab\n";
                cout << "\t\t3. Welcoming Lecture\n";
            }
            else {
                cout << "Invalid course type." << endl;
                return 1;
            }
            cout << "Enter course number: ";
            int courseNumber;
            cin >> courseNumber;
            cin.ignore(); //Clear newline from buffer
            if (courseType == 1 && courseNumber >= 1 && courseNumber <= 4) {
                switch (courseNumber) {
                case 1: student->registerRegularCourse("Math"); break;
                case 2: student->registerRegularCourse("Biology"); break;
                case 3: student->registerRegularCourse("Chemistry"); break;
                case 4: student->registerRegularCourse("English Literature"); break;
                }
                cout << "Congratulations! You have successfully registered for the regular course.\nThe user registration information are : " << endl;
            }
            else if (courseType == 2 && courseNumber >= 1 && courseNumber <= 3) {
                switch (courseNumber) {
                case 1: student->registerSpecialCourse("OOP : Practical course"); break;
                case 2: student->registerSpecialCourse("Physics : Lab"); break;
                case 3: student->registerSpecialCourse("Welcoming Lecture"); break;
                }
                cout << "Congratulations! You have successfully registered for the special course. \n+The user registration information are : " << endl;
            }
            else {
                cout << "Invalid course number." << endl;
                return 1;
            }
        }
        break;
    }
    case 2: {
        string department;
        cout << "Enter Faculty Advisor name: ";
        cin.ignore();
        getline(cin, userName);
        cout << "Enter department (Civil, Software, Computer, Industrial): ";
        cin >> department;
        database.addUser(make_unique<FacultyAdvisor>(userName, department));
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    // Display schedule based on user type
    auto& users = database.getUsers();
    if (!users.empty()) {
        auto& user = users.back();
        if (auto student = dynamic_cast<Student*>(user.get())) {
            student->displayInfo(); //Display student's courses
        }
        else if (auto facultyAdvisor = dynamic_cast<FacultyAdvisor*>(user.get())) {
            database.displayDepartmentSchedule(facultyAdvisor->getDepartment());
        }
        else {
            cout << "Unknown user type." << endl;
            return 1;
        }
    }
    else {
        cout << "No user added." << endl;
        return 1;
    }

    return 0;
}
