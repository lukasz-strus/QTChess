#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King:public ChessPiece
{
public:
    King(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();

    void findUnSafeLocation();
    void moves();

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

#endif // KING_H
