#ifndef ROOKVIEW_H
#define ROOKVIEW_H
#include "chesspieceview.h"

class RookView:public ChessPieceView
{
public:
    RookView(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();
};

#endif // ROOKVIEW_H
