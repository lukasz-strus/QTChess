#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"

class Rook:public ChessPiece
{
public:
    Rook(Side::Values team, QGraphicsItem *parent = 0);
    void setImage();

    void moves();

private:
    void upMove(int row, int col, QString team);
    void downMove(int row, int col, QString team);
    void leftMove(int row, int col, QString team);
    void rightMove(int row, int col, QString team);
};

#endif // ROOK_H
