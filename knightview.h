#ifndef KNIGHTVIEW_H
#define KNIGHTVIEW_H
#include "chesspieceview.h"

class KnightView:public ChessPieceView
{
public:
    KnightView(Side::Values team, QGraphicsItem *parent = 0);

    void setImage();
};

#endif // KNIGHTVIEW_H
