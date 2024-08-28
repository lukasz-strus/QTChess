#include "knight.h"
#include "game.h"

extern Game *game;
Knight::Knight(Side::Values team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Knight::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/horse_white"));
    else
        setPixmap(QPixmap(":/pieces/horse_black"));
}

void Knight::moves()
{
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team  = this->getSideAsString();

     upUpLeft(row, col, team);
     upUpRight(row, col, team);

     downDownLeft(row, col, team);
     downDownRight(row, col, team);

     leftLeftUp(row, col, team);
     leftLeftDown(row, col, team);

     rightRightUp(row, col, team);
     rightRightDown(row, col, team);
}

void Knight::upUpLeft(int row, int col, QString team)
{
    int i = row - 2;
    int j = col - 1;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}

void Knight::upUpRight(int row, int col, QString team)
{
    int i = row - 2;
    int j = col + 1;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}

void Knight::downDownLeft(int row, int col, QString team)
{
    int i = row + 2;
    int j = col - 1;
    if(i <= 7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}

void Knight::downDownRight(int row, int col, QString team)
{
    int i = row + 2;
    int j = col + 1;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}

void Knight::leftLeftUp(int row, int col, QString team)
{
    int i = row - 1;
    int j = col - 2;
    if(i >=0 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}

void Knight::leftLeftDown(int row, int col, QString team)
{
    int i = row + 1;
    int j = col - 2;
    if(i <=7 && j>=0 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}

void Knight::rightRightUp(int row, int col, QString team)
{
    int i = row - 1;
    int j = col + 2;
    if(i >=0 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) ) {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}

void Knight::rightRightDown(int row, int col, QString team)
{
    int i = row + 1;
    int j = col +  2;
    if(i <=7 && j<=7 && (game->collection[i][j]->getChessPieceColor() != team) )
    {
        location.append(game->collection[i][j]);
        if(location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}
