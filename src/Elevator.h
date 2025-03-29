#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Person.h"
#include <vector>

class Elevator
{
public:
    Elevator(unsigned int shaft, int floor) {
        shaft = elevatorShaft;
        currentFloor = floor;

    }
    ~Elevator() {}

    unsigned int elevatorShaft;
    int currentFloor;
    bool isWaiting = true;
    unsigned int fullness = 0;

    std::vector<Person> persons;

    void goToFloor(int floor){

    }

private:
};

#endif // ELEVATOR_H
