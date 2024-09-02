#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"

class Pawn:public ChessPiece
{
public:
    Pawn(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();
};

#endif // PAWN_H
