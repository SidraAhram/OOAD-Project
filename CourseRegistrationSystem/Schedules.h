#ifndef Schedule_H
#define Schedule_H
#include <iostream>
#include <vector>
#include <string>

class Schedule {
    vector<string> scheduleItems;
public:
    void addScheduleItem(string item) {
        scheduleItems.push_back(item);
    }

    vector<string> getSchedule() const {
        return scheduleItems;
    }
};

#endif