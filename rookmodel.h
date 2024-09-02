#ifndef ROOKMODEL_H
#define ROOKMODEL_H
#include "chesspiecemodel.h"

class RookModel:public ChessPieceModel
{
public:
    RookModel(Side::Values team, QGraphicsItem *parent = 0);

    void moves();

private:
    void upMove(int row, int col, QString team);
    void downMove(int row, int col, QString team);
    void leftMove(int row, int col, QString team);
    void rightMove(int row, int col, QString team);
};

#endif // ROOKMODEL_H
