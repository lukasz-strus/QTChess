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
    if(this == game->pieceToMove){
        game->pieceToMove->model->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
        return;
    }

    if((!model->getIsPlaced() )|| ( (game->getTurn() != this->model->getSide())&& (!game->pieceToMove)) )
        return;

    if(!game->pieceToMove){

        game->pieceToMove = this;
        game->pieceToMove->model->getCurrentBox()->setColor(Qt::red);
        game->pieceToMove->model->moves();
    }

    else if(this->model->getSide() != game->pieceToMove->model->getSide()){
        this->model->getCurrentBox()->mousePressEvent(event);
    }
}


void ChessPieceView::decolor()
{
    for(size_t i = 0, n = model->location.size(); i < n;i++) {
        model->location[i]->resetOriginalColor();
    }
}


