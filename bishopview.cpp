#include "bishopview.h"
#include "bishopmodel.h"

BishopView::BishopView(Side::Values team, QGraphicsItem *parent):ChessPieceView(team,parent)
{
    setImage();
    setModel(new BishopModel(team, parent));
}

void BishopView::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/bishop_white"));
    else
        setPixmap(QPixmap(":/pieces/bishop_black"));
}
