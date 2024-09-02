#include "queenview.h"
#include "queenmodel.h"

QueenView::QueenView(Side::Values team, QGraphicsItem *parent):ChessPieceView(team,parent)
{
    setImage();
    setModel(new QueenModel(team, parent));
}

void QueenView::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/queen_white"));
    else
        setPixmap(QPixmap(":/pieces/queen_black"));
}
