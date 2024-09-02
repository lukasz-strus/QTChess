#ifndef KINGVIEW_H
#define KINGVIEW_H
#include "chesspieceview.h"

class KingView:public ChessPieceView
{
public:
    KingView(Side::Values team, QGraphicsItem *parent = 0);

    void setImage();
};

#endif // KINGVIEW_H
