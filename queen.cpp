#include "queen.h"
#include "game.h"

extern Game *game;
Queen::Queen(Side::Values team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void Queen::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/queen_white"));
    else
        setPixmap(QPixmap(":/pieces/queen_black"));
}

void Queen::moves()
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

void Queen::upMove(int row, int col, QString team)
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
void Queen::downMove(int row, int col, QString team)
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
void Queen::leftMove(int row, int col, QString team)
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
void Queen::rightMove(int row, int col, QString team)
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
void Queen::upperLeftMove(int row, int col, QString team)
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
void Queen::upperRightMove(int row, int col, QString team)
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
void Queen::downwardLeftMove(int row, int col, QString team)
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
void Queen::downwardRightMove(int row, int col, QString team)
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
