#ifndef PAWNVIEW_H
#define PAWNVIEW_H
#include "chesspieceview.h"

class PawnView:public ChessPieceView
{
public:
    PawnView(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();
};

#endif // PAWNVIEW_H
