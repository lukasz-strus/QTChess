#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight:public ChessPiece
{
public:
    Knight(Side::Values team, QGraphicsItem *parent = 0);

    void setImage();
};

#endif // KNIGHT_H
