#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"

class Rook:public ChessPiece
{
public:
    Rook(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();
};

#endif // ROOK_H
