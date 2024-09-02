#include "knightview.h"
#include "knightmodel.h"

KnightView::KnightView(Side::Values team, QGraphicsItem *parent):ChessPieceView(team, parent)
{
    setImage();
    setModel(new KnightModel(team, parent));
}

void KnightView::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/horse_white"));
    else
        setPixmap(QPixmap(":/pieces/horse_black"));
}


