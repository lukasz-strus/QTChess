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

    QGraphicsTextItem *bottomText;
    ChessBox *collection[8][8];
    QList <ChessPieceView *> alivePiece;
    ChessPieceView *pieceToMove;

    void drawChessBoard();
    void displayMainMenu();
    void drawDeadHolder(int x, int y,QColor color);
    void displayDeadWhite();
    void displayDeadBlack();
    void placeInDeadPlace(ChessPieceView *piece);

    void addToScene(QGraphicsItem *item);
    void removeFromScene(QGraphicsItem *item);

    Side::Values getTurn();
    void setTurn(Side::Values value);

    Side::Values getFirstTurn();
    void setFirstTurn(Side::Values value);

    void changeTurn();

    void gameOver(Side::Values value);
    void removeAll();
public slots:
    void start();

private:
    QGraphicsScene *scene;
    QList <QGraphicsItem *> listG;
    QGraphicsTextItem * topText;
    ChessBoard *chess;
    QGraphicsRectItem * deadHolder;
    QList <ChessPieceView *> whiteDead;
    QList <ChessPieceView *> blackDead;
    Side::Values turn;

    int blackPoints;
    int whitePoints;
    QGraphicsTextItem* whiteInfo;
    QGraphicsTextItem* blackInfo;

    Side::Values firstTurn;

    void createScene();
    void displayTurn();
    void displayCheck();

    void createTitle();
    void createPlayButton();
    void createQuitButton();

    void setBlackPointsInfo();
    void setWhitePointsInfo();
};


#endif // GAME_H
