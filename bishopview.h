#ifndef BISHOPVIEW_H
#define BISHOPVIEW_H
#include "chesspieceview.h"

class BishopView:public ChessPieceView
{
public:
    BishopView(Side::Values team, QGraphicsItem *parent = 0);

    void setImage();
};

#endif // BISHOPVIEW_H
