#ifndef QUEENVIEW_H
#define QUEENVIEW_H
#include "chesspieceview.h"

class QueenView:public ChessPieceView
{
public:
    QueenView(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();
};

#endif // QUEENVIEW_H
