#include "button.h"
#include <QBrush>
#include <QFont>

Button::Button(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    drawButton();
    drawText(name);
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event)
        emit clicked();

}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if(event){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        setBrush(brush);
    }
}
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    if(event){
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkRed);
        setBrush(brush);
    }
}

void Button::drawText(QString name)
{
    text = new QGraphicsTextItem(name, this);

    QFont font("arial", 16);
    text->setFont(font);

    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::white);
}

void Button::drawButton()
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}
