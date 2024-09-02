#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

class Queen:public ChessPiece
{
public:
    Queen(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();
};

#endif // QUEEN_H
