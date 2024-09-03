#include "chesspieceview.h"
#include "chesspiecemodel.h"
#include "game.h"

extern Game *game;
ChessPieceView::ChessPieceView(
    Side::Values team,
    QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    side = team;
}

void ChessPieceView::setModel(ChessPieceModel *model)
{
    this->model = model;
}

ChessPieceModel *ChessPieceView::getChessModel()
{
    return model;
}

void ChessPieceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(deselect()) return;
    if(pieceIsDeadOrOppositeColor()) return;

    if(!game->pieceToMove)
    {
        select();
    }
    else if(this->model->getSide() != game->pieceToMove->model->getSide())
    {
        tryConsumePiece(event);
    }
}

bool ChessPieceView::deselect()
{
    if(this == game->pieceToMove)
    {
        game->pieceToMove->model->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
        return true;
    }

    return false;
}

bool ChessPieceView::pieceIsDeadOrOppositeColor()
{
    if((!model->getIsPlaced())
        || ((game->getTurn() != this->model->getSide()) && (!game->pieceToMove)))
        return true;

    return false;
}

void ChessPieceView::select()
{
    game->pieceToMove = this;
    game->pieceToMove->model->getCurrentBox()->setColor(Qt::red);
    game->pieceToMove->model->moves();
}

void ChessPieceView::tryConsumePiece(QGraphicsSceneMouseEvent *event)
{
    this->model->getCurrentBox()->mousePressEvent(event);
}

void ChessPieceView::decolor()
{
    for(size_t i = 0, n = model->location.size(); i < n;i++) {
        model->location[i]->resetOriginalColor();
    }
}


