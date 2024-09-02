#include "bishopmodel.h"
#include "game.h"

extern Game *game;
BishopModel::BishopModel(
    Side::Values team,
    QGraphicsItem *parent):ChessPieceModel(team, parent)
{

}

void BishopModel::moves()
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

void BishopModel::downardRightMove(int row, int col, QString side)
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

void BishopModel::downardLeftMove(int row, int col, QString side)
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

void BishopModel::upperRightMove(int row, int col, QString side)
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

void BishopModel::upperLeftMove(int row, int col, QString side)
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
