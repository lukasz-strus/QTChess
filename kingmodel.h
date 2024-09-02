#ifndef KINGMODEL_H
#define KINGMODEL_H
#include "chesspiecemodel.h"

class KingModel:public ChessPieceModel
{
public:
    KingModel(Side::Values team, QGraphicsItem *parent = 0);

    void moves();

    void findUnSafeLocation();

private:
    void upLeftMove(int row, int col, QString team);
    void upRightMove(int row, int col, QString team);
    void upMove(int row, int col, QString team);
    void downMove(int row, int col, QString team);
    void leftMove(int row, int col, QString team);
    void rightMove(int row, int col, QString team);
    void downLeftMove(int row, int col, QString team);
    void downRightMove(int row, int col, QString team);
};

#endif // KINGMODEL_H
