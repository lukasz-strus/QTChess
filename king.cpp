#include "king.h"
#include "game.h"

extern Game *game;
King::King(QString team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void King::setImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/pieces/king_white"));
    else
        setPixmap(QPixmap(":/pieces/king_black"));
}
