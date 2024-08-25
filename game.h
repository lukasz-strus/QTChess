#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include "chessboard.h"
#include "chessbox.h"

class Game:public QGraphicsView
{
    Q_OBJECT


public:
    Game(QWidget *parent = 0);

    QGraphicsTextItem *check;

    ChessBox *collection[8][8];

    void drawChessBoard();
    void displayMainMenu();

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);
private:
    QGraphicsScene *scene;
    QGraphicsTextItem * turnDisplay;
    ChessBoard *chess;

    QList <QGraphicsItem *> listG;

    void createScene();
    void displayTurn();
    void displayCheck();

    void createTitle();


};


#endif // GAME_H
