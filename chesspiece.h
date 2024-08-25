#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QGraphicsPixmapItem>

class ChessPiece:public QGraphicsPixmapItem
{
public:
     ChessPiece(QString team = "",QGraphicsItem *parent = 0);
};

#endif // CHESSPIECE_H
