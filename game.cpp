#include "game.h"
#include "button.h"
#include "king.h"

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    createScene();
    displayTurn();
    displayCheck();

    pieceToMove = NULL;
    setTurn(Side::Values::White);
}

void Game::start()
{
    for(size_t i =0, n = listG.size(); i < n; i++)
        removeFromScene(listG[i]);

    addToScene(turnDisplay);

    QGraphicsTextItem* whitePiece = new QGraphicsTextItem();
    whitePiece->setPos(70,10);
    whitePiece->setZValue(1);
    whitePiece->setDefaultTextColor(Qt::white);
    whitePiece->setFont(QFont("Arial",18));
    whitePiece->setPlainText("Białe pionki");
    addToScene(whitePiece);

    QGraphicsTextItem *blackPiece = new QGraphicsTextItem();
    blackPiece->setPos(1170,10);
    blackPiece->setZValue(1);
    blackPiece->setDefaultTextColor(Qt::black);
    blackPiece->setFont(QFont("Arial",18));
    blackPiece->setPlainText("Czarne pionki");
    addToScene(blackPiece);

    addToScene(check);

    chess->addChessPiece();
}

void Game::displayDeadWhite()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = whiteDead.size(); i<n; i++) {
        if(j == 4){
            k++;
            j = 0;
        }
        whiteDead[i]->setPos(40+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::displayDeadBlack()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = blackDead.size(); i<n; i++) {
        if(j == 4){
            k++;
            j = 0;
        }
        blackDead[i]->setPos(1140+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::placeInDeadPlace(ChessPiece *piece)
{
    if(piece->getSide() == Side::Values::White)
    {
        whiteDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if(g){

            check->setPlainText("Czarny gracz wygrał!");
            gameOver();
        }
        displayDeadWhite();
    }
    else{
        blackDead.append(piece);
        King *g = dynamic_cast <King *>(piece);
        if(g){

            check->setPlainText("Biały gracz wygrał!");
            gameOver();
        }
        displayDeadBlack();
    }
    alivePiece.removeAll(piece);
}

void Game::gameOver()
{
    //removeAll();
    setTurn(Side::Values::White);
    alivePiece.clear();
    chess->reset();

}

void Game::removeAll(){
    QList<QGraphicsItem*> itemsList = scene->items();
    for(size_t i = 0, n = itemsList.size();i<n;i++) {
        if(itemsList[i]!=check)
            removeFromScene(itemsList[i]);
    }
}

Side::Values Game::getTurn()
{
    return turn;
}

void Game::setTurn(Side::Values value)
{
    turn = value;
}

void Game::changeTurn()
{
    QString turn;
    if(getTurn() == Side::Values::White)
    {
        setTurn(Side::Values::Black);
        turn = "czarnego";
    }
    else
    {
        setTurn(Side::Values::White);
        turn = "białego";
    }

    turnDisplay->setPlainText("Kolej gracza " + turn);
}


void Game::displayMainMenu()
{
    createTitle();

    createPlayButton();
    createQuitButton();

    drawChessBoard();
}

void Game::createPlayButton()
{
    Button * button = new Button("Graj");

    int xPos = width()/2 - button->boundingRect().width()/2;
    int yPos = 350;
    button->setPos(xPos,yPos);

    connect(button,SIGNAL(clicked()) , this , SLOT(start()));

    addToScene(button);
    listG.append(button);
}

void Game::createQuitButton()
{
    Button * quitButton = new Button("Wyjdź");

    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 450;
    quitButton->setPos(qxPos,qyPos);

    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));

    addToScene(quitButton);
    listG.append(quitButton);
}

void Game::createTitle()
{
    QGraphicsTextItem *titleText = new QGraphicsTextItem("QT Szachy");

    QFont titleFont("arial", 50);
    titleText->setFont(titleFont);

    int textXPos = width()/2 - titleText->boundingRect().width()/2;
    int textYPos = 200;
    titleText->setPos(textXPos, textYPos);

    int rectWidth = 800;
    int rectHeight = titleText->boundingRect().height() + 40;

    QGraphicsRectItem *backgroundRect = new QGraphicsRectItem(
        textXPos-230,
        textYPos - 20,
        rectWidth,
        rectHeight);

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

    drawDeadHolder(0,0,Qt::lightGray);
    drawDeadHolder(1100,0,Qt::lightGray);

    chess->drawBoxes(width()/2-400,50);
}

void Game::drawDeadHolder(int x, int y,QColor color)
{
    deadHolder = new QGraphicsRectItem(x,y,300,900);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addToScene(deadHolder);
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
    turnDisplay->setDefaultTextColor(Qt::red);
    turnDisplay->setFont(QFont("Arial",18));
    turnDisplay->setPlainText("Kolej gracza białego");

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
