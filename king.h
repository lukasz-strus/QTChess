#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King:public ChessPiece
{
public:
    King(Side::Values team, QGraphicsItem *parent = 0);

    void setImage();
};

#endif // KING_H
