#include "bishop.h"
#include "bishopmodel.h"

Bishop::Bishop(Side::Values team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
    setModel(new BishopModel(team, parent));
}

void Bishop::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/bishop_white"));
    else
        setPixmap(QPixmap(":/pieces/bishop_black"));
}
