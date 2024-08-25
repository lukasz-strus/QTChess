#include "game.h"

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    createScene();
    displayTurn();
    displayCheck();
}

void Game::displayMainMenu()
{
    drawChessBoard();
}

void Game::drawChessBoard()
{
    chess = new ChessBoard();

    chess->drawBoxes(width()/2-400,50);
}


void Game::addToScene(QGraphicsItem *item)
{
    scene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item)
{
    scene->removeItem(item);

}

void Game::displayCheck()
{
    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,860);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",18));
    check->setPlainText("CHECK!");
    check->setVisible(false);
}

void Game::displayTurn()
{
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100,10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : WHITE");

}

void Game::createScene()
{
    setFixedSize(1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene();
    scene -> setSceneRect(0, 0, 1400, 900);
    setScene(scene);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
}
