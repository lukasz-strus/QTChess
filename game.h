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
    QList <ChessPiece *> alivePiece;
    ChessPiece *pieceToMove;

    void drawChessBoard();
    void displayMainMenu();
    void drawDeadHolder(int x, int y,QColor color);
    void displayDeadWhite();
    void displayDeadBlack();
    void placeInDeadPlace(ChessPiece *piece);

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    Side::Values getTurn();
    void setTurn(Side::Values value);
    void changeTurn();

    void gameOver();
    void removeAll();
public slots:
    void start();

private:
    QGraphicsScene *scene;
    QList <QGraphicsItem *> listG;
    QGraphicsTextItem * turnDisplay;
    ChessBoard *chess;
    QGraphicsRectItem * deadHolder;
    QList <ChessPiece *> whiteDead;
    QList <ChessPiece *> blackDead;
    Side::Values turn;

    void createScene();
    void displayTurn();
    void displayCheck();

    void createTitle();
    void createPlayButton();
    void createQuitButton();

};


#endif // GAME_H
