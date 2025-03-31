#ifndef UTILS_H
#define UTILS_H

#include <QDebug>
#include <QLabel>
#include <vector>
#include <QPixmap>

const int MAXFLOOR = 6;
const int MINFLOOR = 0;
const int MAXSHAFT = 8;

extern std::vector<QLabel *> label_elevator;
extern std::vector<QLabel *> people;

#endif // UTILS_H
