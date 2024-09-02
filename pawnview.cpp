#include "pawnview.h"
#include "pawnmodel.h"

PawnView::PawnView(Side::Values team,QGraphicsItem *parent):ChessPieceView(team,parent)
{
    setImage();
    setModel(new PawnModel(team, parent));
}

void PawnView::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/pawn_white"));
    else
        setPixmap(QPixmap(":/pieces/pawn_black"));
}


