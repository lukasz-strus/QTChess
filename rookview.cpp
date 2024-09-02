#include "rookview.h"
#include "rookmodel.h"

RookView::RookView(Side::Values team,QGraphicsItem *parent):ChessPieceView(team, parent)
{
    setImage();
    setModel(new RookModel(team, parent));
}


void RookView::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/rook_white"));
    else
        setPixmap(QPixmap(":/pieces/rook_black"));
}
