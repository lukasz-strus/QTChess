#include "king.h"
#include "kingmodel.h"

King::King(Side::Values team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
    setModel(new KingModel(team, parent));
}

void King::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/king_white"));
    else
        setPixmap(QPixmap(":/pieces/king_black"));
}

