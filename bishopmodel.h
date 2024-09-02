#ifndef BISHOPMODEL_H
#define BISHOPMODEL_H
#include "chesspiecemodel.h"

class BishopModel:public ChessPieceModel
{
public:
    BishopModel(Side::Values team, QGraphicsItem *parent = 0);

    void moves();

private:
    void upperLeftMove(int row, int col, QString side);
    void upperRightMove(int row, int col, QString side);
    void downardLeftMove(int row, int col, QString side);
    void downardRightMove(int row, int col, QString side);
};

#endif // BISHOPMODEL_H
