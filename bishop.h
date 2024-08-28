#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

class Bishop:public ChessPiece
{
public:
    Bishop(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();

    void moves();

private:
    void upperLeftMove(int row, int col, QString side);
    void upperRightMove(int row, int col, QString side);
    void downardLeftMove(int row, int col, QString side);
    void downardRightMove(int row, int col, QString side);
};

#endif // BISHOP_H
