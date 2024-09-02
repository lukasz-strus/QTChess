#include "kingview.h"
#include "kingmodel.h"

KingView::KingView(Side::Values team, QGraphicsItem *parent):ChessPieceView(team,parent)
{
    setImage();
    setModel(new KingModel(team, parent));
}

void KingView::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/king_white"));
    else
        setPixmap(QPixmap(":/pieces/king_black"));
}

