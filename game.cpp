#include "game.h"

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    createScene();
    displayTurn();
    displayCheck();
}

void Game::displayMainMenu()
{
    createTitle();
    drawChessBoard();
}

void Game::createTitle()
{
    QGraphicsTextItem *titleText = new QGraphicsTextItem("QT Szachy");
    QFont titleFont("arial", 50);
    titleText->setFont(titleFont);

    int textXPos = width()/2 - titleText->boundingRect().width()/2;
    int textYPos = 200;
    titleText->setPos(textXPos, textYPos);

    int rectWidth = 800; // Pełna szerokość sceny
    int rectHeight = titleText->boundingRect().height() + 40;

    QGraphicsRectItem *backgroundRect = new QGraphicsRectItem(textXPos-230, textYPos - 20, rectWidth, rectHeight);

    // Ustawienie półprzezroczystego szarego koloru
    QBrush brush(QColor(255, 255, 255, 180));
    backgroundRect->setBrush(brush);
    backgroundRect->setPen(Qt::NoPen);

    addToScene(backgroundRect);
    addToScene(titleText);

    listG.append(backgroundRect);
    listG.append(titleText);

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
