#ifndef User_H
#define User_H
#include <string>

class User {
protected:
    std::string userName;
public:
    User(std::string name) : userName(name) {}

    virtual void displayInfo() const = 0; // Our pure virtual function
};

#endif