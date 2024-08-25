#ifndef CHESSBOX_H
#define CHESSBOX_H
#include <QGraphicsRectItem>
#include <QBrush>

class ChessBox:public QGraphicsRectItem
{
public:
    ChessBox(QGraphicsItem *parent=0);

    int rowLoc;
    int colLoc;

    void setOriginalColor(QColor value);
    void setColor(QColor value);

private:
    QBrush brush;
    QColor originalColor;
};

#endif // CHESSBOX_H
