#include "bishop.h"
#include "game.h"

extern Game *game;
Bishop::Bishop(Side::Values team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Bishop::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/bishop_white"));
    else
        setPixmap(QPixmap(":/pieces/bishop_black"));
}

void Bishop::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString side = this->getSideAsString();

    upperLeftMove(row, col, side);
    upperRightMove(row, col, side);
    downardLeftMove(row, col, side);
    downardRightMove(row, col, side);
}

void Bishop::downardRightMove(int row, int col, QString side)
{
    for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
        if(game->collection[i][j]->getChessPieceColor() == side) break;

        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())) break;
        }
    }
}

void Bishop::downardLeftMove(int row, int col, QString side)
{
    for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++)
    {
        if(game->collection[i][j]->getChessPieceColor() == side) break;

        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())) break;
        }
    }
}

void Bishop::upperRightMove(int row, int col, QString side)
{
    for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++)
    {
        if(game->collection[i][j]->getChessPieceColor() == side) break;

        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())) break;

        }
    }
}

void Bishop::upperLeftMove(int row, int col, QString side)
{
    for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--)
    {
        if(game->collection[i][j]->getChessPieceColor() == side) break;

        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())) break;

        }
    }
}
