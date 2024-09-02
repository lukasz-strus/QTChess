#ifndef CHESSPIECEMODEL_H
#define CHESSPIECEMODEL_H
#include <QGraphicsPixmapItem>
#include "side.h"

class ChessBox;
class ChessPieceModel:public QGraphicsPixmapItem
{
public:
    ChessPieceModel(Side::Values team, QGraphicsItem *parent = 0);

    QList <ChessBox *> location;

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

    bool boxSetting(ChessBox *box);
protected:
    Side::Values side;
    ChessBox *currentBox;
    bool isPlaced;
};

#endif // CHESSPIECEMODEL_H
