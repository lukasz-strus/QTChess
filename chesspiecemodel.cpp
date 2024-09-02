#include "chesspiecemodel.h"
#include "king.h"
#include "game.h"

extern Game *game;
ChessPieceModel::ChessPieceModel(Side::Values team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    firstMove = true;
    isPlaced = true;
}

bool ChessPieceModel::getIsPlaced()
{
    return isPlaced;
}

void ChessPieceModel::setIsPlaced(bool value)
{
    isPlaced = value;
}

void ChessPieceModel::setCurrentBox(ChessBox *box)
{
    currentBox = box;
}

ChessBox *ChessPieceModel::getCurrentBox()
{
    return currentBox;
}

QList<ChessBox *> ChessPieceModel::moveLocation()
{
    return location;
}

Side::Values ChessPieceModel::getSide()
{
    return side;
}

QString ChessPieceModel::getSideAsString()
{
    if(side == Side::Values::White)
        return "WHITE";
    else
        return "BLACK";
}

void ChessPieceModel::setSide(Side::Values value)
{
    side = value;
}

bool ChessPieceModel::boxSetting(ChessBox *box)
{
    if(box->getHasChessPiece()) {
        King *q = dynamic_cast<King*>(location.last()->currentPiece);
        if(q){
            box->setColor(Qt::blue);
        }
        else
            box->setColor(Qt::red);
        return true;
    }
    else
        location.last()->setColor(Qt::darkRed);
    return false;
}
