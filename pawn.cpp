#include "pawn.h"
#include "game.h"

extern Game * game;
Pawn::Pawn(Side::Values team,QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
    firstMove = true;
}

void Pawn::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/pawn_white"));
    else
        setPixmap(QPixmap(":/pieces/pawn_black"));
}

void Pawn::moves()
{
    location.clear();

    int row = this->getCurrentBox()->rowLoc;

    int col = this->getCurrentBox()->colLoc;
    if(this->getSide() == Side::Values::White)  {
        if(col > 0 && row > 0 && game->collection[row-1][col-1]->getChessPieceColor() == "BLACK") {
            location.append(game->collection[row-1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row > 0 && game->collection[row-1][col+1]->getChessPieceColor() == "BLACK") {
            location.append(game->collection[row-1][col+1]);
            boxSetting(location.last());
        }
        if(row>0 && (!game->collection[row-1][col]->getHasChessPiece())) {
            location.append(game->collection[row-1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row-2][col]->getHasChessPiece()){
                location.append(game->collection[row-2][col]);
                boxSetting(location.last());
            }
        }

    }
    else{
        if(col > 0 && row < 7 && game->collection[row+1][col-1]->getChessPieceColor() == "WHITE") {//left
            location.append(game->collection[row+1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row <  7 && game->collection[row+1][col+1]->getChessPieceColor() == "WHITE") {//right
            location.append(game->collection[row+1][col+1]);
            boxSetting(location.last());
        }
        if(row<7 && (!game->collection[row+1][col]->getHasChessPiece())) {
            location.append(game->collection[row+1][col]);
            boxSetting(location.last());
            if(firstMove && !game->collection[row+2][col]->getHasChessPiece()){
                location.append(game->collection[row+2][col]);
                boxSetting(location.last());
            }

        }

    }

}
