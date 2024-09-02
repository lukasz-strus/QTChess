#ifndef QUEENMODEL_H
#define QUEENMODEL_H
#include "chesspiecemodel.h"

class QueenModel:public ChessPieceModel
{
public:
    QueenModel(Side::Values team, QGraphicsItem *parent = 0);

    void moves();

private:
    void upMove(int row, int col, QString team);
    void downMove(int row, int col, QString team);
    void leftMove(int row, int col, QString team);
    void rightMove(int row, int col, QString team);
    void upperLeftMove(int row, int col, QString team);
    void upperRightMove(int row, int col, QString team);
    void downwardLeftMove(int row, int col, QString team);
    void downwardRightMove(int row, int col, QString team);
};

#endif // QUEENMODEL_H
