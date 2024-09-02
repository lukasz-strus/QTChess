#ifndef PAWNMODEL_H
#define PAWNMODEL_H
#include "chesspiecemodel.h"

class PawnModel:public ChessPieceModel
{
public:
    PawnModel(Side::Values team, QGraphicsItem *parent = 0);

    void moves();
};

#endif // PAWNMODEL_H
