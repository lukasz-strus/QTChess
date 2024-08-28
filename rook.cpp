#include "rook.h"
#include "game.h"

extern Game *game;
Rook::Rook(Side::Values team,QGraphicsItem *parent):ChessPiece(team, parent)
{
    setImage();
}


void Rook::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/rook_white"));
    else
        setPixmap(QPixmap(":/pieces/rook_black"));
}

void Rook::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSideAsString();

    upMove(row, col, team);
    downMove(row, col, team);
    leftMove(row, col, team);
    rightMove(row, col, team);
}

void Rook::upMove(int row, int col, QString team)
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
void Rook::downMove(int row, int col, QString team)
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
void Rook::leftMove(int row, int col, QString team)
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
void Rook::rightMove(int row, int col, QString team)
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
