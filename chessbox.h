#ifndef CHESSBOX_H
#define CHESSBOX_H
#include <QGraphicsRectItem>
#include <QBrush>
#include "chesspieceview.h"

class ChessBox:public QGraphicsRectItem
{
public:
    ChessBox(QGraphicsItem *parent=0);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    int rowLoc;
    int colLoc;

    ChessPieceView * currentPiece;

    void resetOriginalColor();
    void setOriginalColor(QColor value);
    void setColor(QColor value);

    void placePiece(ChessPieceView *piece);

    void checkForCheck();

    bool getHasChessPiece();
    void setHasChessPiece(bool value, ChessPieceView *piece = 0);

    QString getChessPieceColor() ;
    void setChessPieceColor(QString value);

private:
    QBrush brush;
    QColor originalColor;
    bool hasChessPiece;
    QString chessPieceColor;
};

#endif // CHESSBOX_H
