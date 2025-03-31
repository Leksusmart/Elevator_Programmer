#ifndef PERSON_H
#define PERSON_H

#include "utils.h"

class Person
{
public:
    Person(int floor, QWidget *parent)
    {
        startFloor = floor;
        people.push_back(new QLabel(parent));
        id = people.size() - 1;
        people[id]->setGeometry(QRect(rand() % 170, 40 + (600 - 100 * startFloor), 33, 60));
        people[id]->setPixmap(personImage);
        do {
            endFloor = rand() % (abs(MINFLOOR) + MAXFLOOR + 1) - MINFLOOR;
            qDebug() << "while endFloor == startFloor";
        } while (endFloor == startFloor);
        qDebug() << "Created person on floor" << startFloor<<". His goal is floor"<<endFloor<< "id " << id;;
    }
    ~Person()
    {
        delete people[id];
        people[id] = nullptr;
    }

    QPixmap personImage = QPixmap("://images/person.png")
                              .scaled(33, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    int id;
    int startFloor;
    int endFloor;

    void *onElevator = nullptr;

public slots:

private:

};

#endif // PERSON_H
