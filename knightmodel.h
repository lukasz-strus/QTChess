#ifndef KNIGHTMODEL_H
#define KNIGHTMODEL_H
#include "chesspiecemodel.h"

class KnightModel:public ChessPieceModel
{
public:
    KnightModel(Side::Values team, QGraphicsItem *parent = 0);

    void moves();

private:
    void upUpLeft(int row, int col, QString team);
    void upUpRight(int row, int col, QString team);

    void downDownLeft(int row, int col, QString team);
    void downDownRight(int row, int col, QString team);

    void leftLeftUp(int row, int col, QString team);
    void leftLeftDown(int row, int col, QString team);

    void rightRightUp(int row, int col, QString team);
    void rightRightDown(int row, int col, QString team);
};

#endif // KNIGHTMODEL_H
