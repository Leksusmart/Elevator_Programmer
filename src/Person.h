#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person(int floor) { startFloor = floor; }
    ~Person(){}

    int startFloor;
    int dirFloor;
    void *onElevator = nullptr;
private:

};

#endif // PERSON_H
