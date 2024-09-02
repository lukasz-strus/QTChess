#include "queen.h"
#include "queenmodel.h"

Queen::Queen(Side::Values team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
    setModel(new QueenModel(team, parent));
}

void Queen::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/queen_white"));
    else
        setPixmap(QPixmap(":/pieces/queen_black"));
}
