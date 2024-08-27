#include "chesspiece.h"
#include "game.h"

extern Game *game;
ChessPiece::ChessPiece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Deselect
    if(this == game->pieceToMove){
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
        return;
    }
    //if it is already consumed or not the respective color's turn
    if((!getIsPlaced() )|| ( (game->getTurn() != this->getSide())&& (!game->pieceToMove)) )
        return;
    //selecting
    if(!game->pieceToMove){

        game->pieceToMove = this;
        game->pieceToMove->getCurrentBox()->setColor(Qt::red);
        game->pieceToMove->moves();
    }
    //Consuming counterPart of the CHessBox
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

QString ChessPiece::getSide()
{
    return side;
}

void ChessPiece::setSide( QString value)
{
    side = value;
}

void ChessPiece::decolor()
{
    for(size_t i = 0, n = location.size(); i < n;i++) {
        location[i]->resetOriginalColor();
    }
}
