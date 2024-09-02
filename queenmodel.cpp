#include "queenmodel.h"
#include "game.h"

extern Game * game;
QueenModel::QueenModel(
    Side::Values team,
    QGraphicsItem *parent):ChessPieceModel(team, parent)
{

}

void QueenModel::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSideAsString();

    upMove(row, col, team);
    downMove(row, col, team);
    leftMove(row, col, team);
    rightMove(row, col, team);
    upperLeftMove(row, col, team);
    upperRightMove(row, col, team);
    downwardLeftMove(row, col, team);
    downwardRightMove(row, col, team);
}

void QueenModel::upMove(int row, int col, QString team)
{
    for(int i = row-1,j = col; i >= 0 ; i--) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }
}
void QueenModel::downMove(int row, int col, QString team)
{
    for(int i = row+1,j = col; i <= 7 ; i++) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
}
void QueenModel::leftMove(int row, int col, QString team)
{
    for(int i = row,j = col-1; j >= 0 ; j--) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }
    }
}
void QueenModel::rightMove(int row, int col, QString team)
{
    for(int i = row,j = col+1; j <= 7 ; j++)
    {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()))
                break;
        }

    }
}
void QueenModel::upperLeftMove(int row, int col, QString team)
{
    for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last()) ){
                break;
            }
        }
    }
}
void QueenModel::upperRightMove(int row, int col, QString team)
{
    for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
}
void QueenModel::downwardLeftMove(int row, int col, QString team)
{
    for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
    }
}
void QueenModel::downwardRightMove(int row, int col, QString team)
{
    for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
        if(game->collection[i][j]->getChessPieceColor() == team ) {
            break;

        }
        else
        {
            location.append(game->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }

        }
    }
}
