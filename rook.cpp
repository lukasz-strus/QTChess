#include "rook.h"
#include "rookmodel.h"

Rook::Rook(Side::Values team,QGraphicsItem *parent):ChessPiece(team, parent)
{
    setImage();
    setModel(new RookModel(team, parent));
}


void Rook::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/rook_white"));
    else
        setPixmap(QPixmap(":/pieces/rook_black"));
}
