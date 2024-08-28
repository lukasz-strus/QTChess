#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QGraphicsPixmapItem>
#include "side.h"

class ChessBox;
class ChessPiece:public QGraphicsPixmapItem
{
public:
    ChessPiece(Side::Values team, QGraphicsItem *parent = 0);

     void mousePressEvent(QGraphicsSceneMouseEvent *event);

     bool firstMove;
     virtual void moves() = 0;

     ChessBox *getCurrentBox();
     void setCurrentBox(ChessBox *box);

     bool getIsPlaced();
     void setIsPlaced(bool value);

     Side::Values getSide();
     QString getSideAsString();
     void setSide(Side::Values value);

     QList <ChessBox *> moveLocation();

     void decolor();

     bool boxSetting(ChessBox *box);
 protected:
     ChessBox *currentBox;
     Side::Values side;
     bool isPlaced;
     QList <ChessBox *> location;
};

#endif // CHESSPIECE_H
