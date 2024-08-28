#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

class Queen:public ChessPiece
{
public:
    Queen(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();

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

#endif // QUEEN_H
