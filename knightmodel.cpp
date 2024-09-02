#include "knightmodel.h"
#include "game.h"


extern Game *game;
KnightModel::KnightModel(
    Side::Values team,
    QGraphicsItem *parent):ChessPieceModel(team, parent)
{

}

void KnightModel::moves()
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

void KnightModel::upUpLeft(int row, int col, QString team)
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

void KnightModel::upUpRight(int row, int col, QString team)
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

void KnightModel::downDownLeft(int row, int col, QString team)
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

void KnightModel::downDownRight(int row, int col, QString team)
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

void KnightModel::leftLeftUp(int row, int col, QString team)
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

void KnightModel::leftLeftDown(int row, int col, QString team)
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

void KnightModel::rightRightUp(int row, int col, QString team)
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

void KnightModel::rightRightDown(int row, int col, QString team)
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
