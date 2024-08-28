#include "king.h"
#include "game.h"
#include "pawn.h"

extern Game *game;
King::King(Side::Values team, QGraphicsItem *parent):ChessPiece(team,parent)
{
    setImage();
}

void King::setImage()
{
    if(side == Side::Values::White)
        setPixmap(QPixmap(":/pieces/king_white"));
    else
        setPixmap(QPixmap(":/pieces/king_black"));
}

void King::moves()
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

void King::upLeftMove(int row, int col, QString team)
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

void King::upRightMove(int row, int col, QString team)
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

void King::upMove(int row, int col, QString team)
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

void King::downMove(int row, int col, QString team)
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

void King::leftMove(int row, int col, QString team)
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

void King::rightMove(int row, int col, QString team)
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

void King::downLeftMove(int row, int col, QString team)
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

void King::downRightMove(int row, int col, QString team)
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


void King::findUnSafeLocation()
{
    QList <ChessPiece *> pList = game->alivePiece;
    for(size_t i = 0,n = pList.size(); i < n; i++)
    {
        if(pList[i]->getSide() != this->getSide())
        {
            QList <ChessBox *> bList = pList[i]->moveLocation();

            for(size_t j = 0, n = bList.size(); j < n; j++) {
                Pawn *c = dynamic_cast<Pawn *> (pList[i]) ;
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
