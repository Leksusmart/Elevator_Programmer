#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "utils.h"

#include <QWidget>
#include <QPropertyAnimation>
#include <QTimer>

class Elevator
{
public:
    Elevator(int shaft,
             int floor,
             QWidget *parent)
    {
        currentShaft = shaft;
        currentFloor = floor;
        if (label_elevator.size() > shaft) {
            label_elevator[shaft] = new QLabel(parent);
            label_elevator[shaft]->setGeometry(
                QRect(201 + 100 * shaft, 2 + (600 - 100 * floor), 98, 98));
            label_elevator[shaft]->setPixmap(elevatorImage);

            qDebug() << "Elevator (" << shaft << "," << floor << ") created on"
                     << label_elevator[shaft]->pos();
        } else {
            qDebug() << "failed to create Elevator on shaft:" << shaft << " and floor:" << floor
                     << "  Size of label_elevator:" << label_elevator.size();
        }
    }
    ~Elevator()
    {
        if (label_elevator[currentShaft] != nullptr)
            delete label_elevator[currentShaft];
        label_elevator[currentShaft] = nullptr;
    }

    QPixmap elevatorImage = QPixmap("://images/Elevator.png")
                                .scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    unsigned int currentShaft;
    int currentFloor;
    bool isWaiting = true;
    unsigned int fullness = 0;

    void goToFloor(int floor)
    {
        if(floor >MAXFLOOR)

        qDebug() << "move called to " << floor;

        QPropertyAnimation *animation = new QPropertyAnimation(label_elevator[currentShaft], "pos");
        QPoint endPos = QPoint(label_elevator[currentShaft]->x(), 2 + (600 - 100 * floor));
        unsigned int duration = abs(currentFloor - floor) * 2000;
        qDebug() << "endPos" << endPos << "duration = " << duration;
        if (duration == 0) {
            delete animation;
            return;
        }

        animation->setStartValue(label_elevator[currentShaft]->pos());
        animation->setEndValue(endPos);
        animation->setDuration(duration);
        animation->setEasingCurve(QEasingCurve::Linear);

        qDebug() << "Elevator before pos =" << label_elevator[currentShaft]->pos();
        animation->start();

        QTimer::singleShot(duration, [this, floor, animation, endPos]() {
            animation->deleteLater();
            qDebug() << "Elevator moved from " << currentFloor << " to " << floor;
            currentFloor = floor;
            qDebug() << "Elevator after pos =" << label_elevator[currentShaft]->pos();

            if (label_elevator[currentShaft]->pos() != endPos){
                label_elevator[currentShaft]->move(endPos);
                qDebug() << "Elevator corrected pos =" << label_elevator[currentShaft]->pos();
            }
        });
    }

private:

};

#endif // ELEVATOR_H
