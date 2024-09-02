#include "knight.h"
#include "knightmodel.h"

Knight::Knight(Side::Values team, QGraphicsItem *parent):ChessPiece(team, parent)
{
    setImage();
    setModel(new KnightModel(team, parent));
}

void Knight::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/horse_white"));
    else
        setPixmap(QPixmap(":/pieces/horse_black"));
}


