#ifndef CHESSPIECEVIEW_H
#define CHESSPIECEVIEW_H
#include <QGraphicsPixmapItem>
#include "side.h"
#include "chesspiecemodel.h"

class ChessPieceView:public QGraphicsPixmapItem
{
public:
    ChessPieceView(Side::Values team, QGraphicsItem *parent = 0);

    ChessPieceModel *getChessModel();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void decolor();

 protected:
     Side::Values side;
     ChessPieceModel *model;

     void setModel(ChessPieceModel *model);
};

#endif // CHESSPIECE_H
