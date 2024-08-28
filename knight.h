#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight:public ChessPiece
{
public:
    Knight(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();

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

#endif // KNIGHT_H
