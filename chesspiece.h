#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QGraphicsPixmapItem>

class ChessBox;
class ChessPiece:public QGraphicsPixmapItem
{
public:
     ChessPiece(QString team = "",QGraphicsItem *parent = 0);

     void mousePressEvent(QGraphicsSceneMouseEvent *event);

     bool firstMove;

     virtual void moves() = 0;

     ChessBox *getCurrentBox();
     void setCurrentBox(ChessBox *box);

     bool getIsPlaced();
     void setIsPlaced(bool value);

     QString getSide();
     void setSide( QString value);

     QList <ChessBox *> moveLocation();

     void decolor();
 protected:
     ChessBox *currentBox;
     QString side;
     bool isPlaced;
     QList <ChessBox *> location;
};

#endif // CHESSPIECE_H
