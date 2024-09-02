#include "pawn.h"
#include "pawnmodel.h"

Pawn::Pawn(Side::Values team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
    setModel(new PawnModel(team, parent));
}

void Pawn::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/pawn_white"));
    else
        setPixmap(QPixmap(":/pieces/pawn_black"));
}


