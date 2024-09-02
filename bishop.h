#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

class Bishop:public ChessPiece
{
public:
    Bishop(Side::Values team, QGraphicsItem *parent = 0);

    void setImage();
};

#endif // BISHOP_H
