#include "chessbox.h"

ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}

void ChessBox::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}

void ChessBox::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}
