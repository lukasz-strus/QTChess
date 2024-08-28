#include "chesspiece.h"
#include "game.h"
#include "king.h"

extern Game *game;
ChessPiece::ChessPiece(Side::Values team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this == game->pieceToMove){
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
        return;
    }

    if((!getIsPlaced() )|| ( (game->getTurn() != this->getSide())&& (!game->pieceToMove)) )
        return;

    if(!game->pieceToMove){

        game->pieceToMove = this;
        game->pieceToMove->getCurrentBox()->setColor(Qt::red);
        game->pieceToMove->moves();
    }

    else if(this->getSide() != game->pieceToMove->getSide()){
        this->getCurrentBox()->mousePressEvent(event);
    }
}

QList<ChessBox *> ChessPiece::moveLocation()
{
    return location;
}

bool ChessPiece::getIsPlaced()
{
    return isPlaced;
}

void ChessPiece::setIsPlaced(bool value)
{
    isPlaced = value;
}

void ChessPiece::setCurrentBox(ChessBox *box)
{
    currentBox = box;
}

ChessBox *ChessPiece::getCurrentBox()
{
    return currentBox;
}

Side::Values ChessPiece::getSide()
{
    return side;
}

QString ChessPiece::getSideAsString()
{
    if(side == Side::Values::White)
        return "WHITE";
    else
        return "BLACK";
}

void ChessPiece::setSide(Side::Values value)
{
    side = value;
}

void ChessPiece::decolor()
{
    for(size_t i = 0, n = location.size(); i < n;i++) {
        location[i]->resetOriginalColor();
    }
}

bool ChessPiece::boxSetting(ChessBox *box)
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
