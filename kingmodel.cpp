#include "kingmodel.h"
#include "game.h"
#include "pawnview.h"

extern Game *game;
KingModel::KingModel(
    Side::Values team,
    QGraphicsItem *parent):ChessPieceModel(team, parent)
{

}

void KingModel::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getSideAsString();

    upLeftMove(row, col, team);
    upRightMove(row, col, team);
    upMove(row, col, team);
    downMove(row, col, team);
    leftMove(row, col, team);
    rightMove(row, col, team);
    downLeftMove(row, col, team);
    downRightMove(row, col, team);

    findUnSafeLocation();
}

void KingModel::upLeftMove(int row, int col, QString team)
{
    if(col > 0 && row > 0 && !(game->collection[row-1][col-1]->getChessPieceColor() == team))
    {
        location.append(game->collection[row-1][col-1]);
        game->collection[row-1][col-1]->setColor(Qt::darkRed);
        if(location.last()->getHasChessPiece())
        {
            location.last()->setColor(Qt::red);
        }
    }
}

void KingModel::upRightMove(int row, int col, QString team)
{
    if(col < 7 && row > 0 && !(game->collection[row-1][col+1]->getChessPieceColor() == team))
    {
        location.append(game->collection[row-1][col+1]);
        game->collection[row-1][col+1]->setColor(Qt::darkRed);
        if(location.last()->getHasChessPiece())
        {
            location.last()->setColor(Qt::red);
        }
    }
}

void KingModel::upMove(int row, int col, QString team)
{
    if(row>0 && !(game->collection[row-1][col]->getChessPieceColor() == team))
    {
        location.append(game->collection[row-1][col]);
        game->collection[row-1][col]->setColor(Qt::darkRed);
        if(location.last()->getHasChessPiece())
        {
            location.last()->setColor(Qt::red);
        }
    }
}

void KingModel::downMove(int row, int col, QString team)
{
    if(row<7 && !(game->collection[row+1][col]->getChessPieceColor() == team))
    {
        location.append(game->collection[row+1][col]);
        game->collection[row+1][col]->setColor(Qt::darkRed);
        if(location.last()->getHasChessPiece())
        {
            location.last()->setColor(Qt::red);
        }
    }
}

void KingModel::leftMove(int row, int col, QString team)
{
    if(col>0 && !(game->collection[row][col-1]->getChessPieceColor() == team))
    {
        location.append(game->collection[row][col-1]);
        game->collection[row][col-1]->setColor(Qt::darkRed);
        if(location.last()->getHasChessPiece())
        {
            location.last()->setColor(Qt::red);
        }
    }
}

void KingModel::rightMove(int row, int col, QString team)
{
    if(col<7 && !(game->collection[row][col+1]->getChessPieceColor() == team))
    {
        location.append(game->collection[row][col+1]);
        game->collection[row][col+1]->setColor(Qt::darkRed);
        if(location.last()->getHasChessPiece())
        {
            location.last()->setColor(Qt::red);
        }
    }
}

void KingModel::downLeftMove(int row, int col, QString team)
{
    if(col > 0 && row < 7  && !(game->collection[row+1][col-1]->getChessPieceColor() == team))
    {
        location.append(game->collection[row+1][col-1]);
        game->collection[row+1][col-1]->setColor(Qt::darkRed);
        if(location.last()->getHasChessPiece())
        {
            location.last()->setColor(Qt::red);
        }
    }
}

void KingModel::downRightMove(int row, int col, QString team)
{
    if(col < 7 && row < 7 && !(game->collection[row+1][col+1]->getChessPieceColor() == team))
    {
        location.append(game->collection[row+1][col+1]);
        game->collection[row+1][col+1]->setColor(Qt::darkRed);
        if(location.last()->getHasChessPiece())
        {
            location.last()->setColor(Qt::red);
        }
    }
}


void KingModel::findUnSafeLocation()
{
    QList <ChessPieceView *> pList = game->alivePiece;
    for(size_t i = 0,n = pList.size(); i < n; i++)
    {
        if(pList[i]->getChessModel()->getSide() != this->getSide())
        {
            QList <ChessBox *> bList = pList[i]->getChessModel()->moveLocation();

            for(size_t j = 0, n = bList.size(); j < n; j++) {
                PawnView *c = dynamic_cast<PawnView *> (pList[i]) ;
                if(c)
                    continue;
                for(size_t k = 0, n = location.size(); k < n; k++) {
                    if(bList[j] == location [k]) {
                        location[k]->setColor(Qt::blue);
                    }
                }
            }
        }
    }
}
