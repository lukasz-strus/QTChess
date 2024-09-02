#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsRectItem>
#include "chesspieceview.h"

class ChessBoard
{
public:
    ChessBoard();

    void drawBoxes(int x, int y);

    void setUpWhite();
    void setUpBlack();

    void addChessPiece();
    void reset();

private:
    QList <ChessPieceView *> white;
    QList <ChessPieceView *> black;
};

#endif // CHESSBOARD_H
