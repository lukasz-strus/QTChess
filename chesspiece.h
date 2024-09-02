#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QGraphicsPixmapItem>
#include "side.h"
#include "chesspiecemodel.h"

class ChessPiece:public QGraphicsPixmapItem
{
public:
    ChessPiece(Side::Values team, QGraphicsItem *parent = 0);

    ChessPieceModel *getChessModel();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void decolor();

 protected:
     Side::Values side;
     ChessPieceModel *model;

     void setModel(ChessPieceModel *model);
};

#endif // CHESSPIECE_H
