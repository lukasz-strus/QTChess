#ifndef SIDE_H
#define SIDE_H

#include <QObject>

class Side: public QObject
{

    Q_OBJECT

public:
    enum class Values: int
    {
        White = 1,
        Black = 2,
    };
    Q_ENUM(Values)
};

#endif // SIDE_H
