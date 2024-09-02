#include "game.h"
#include "button.h"
#include "kingview.h"

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    createScene();
    displayTurn();
    displayCheck();

    blackPoints = 0;
    whitePoints = 0;

    pieceToMove = NULL;
    setFirstTurn(Side::Values::White);
}

void Game::start()
{
    for(size_t i =0, n = listG.size(); i < n; i++)
        removeFromScene(listG[i]);

    addToScene(topText);

    whiteInfo = new QGraphicsTextItem();
    whiteInfo->setPos(50,10);
    whiteInfo->setZValue(1);
    whiteInfo->setDefaultTextColor(Qt::white);
    whiteInfo->setFont(QFont("Arial",18));
    setWhitePointsInfo();
    addToScene(whiteInfo);

    blackInfo = new QGraphicsTextItem();
    blackInfo->setPos(1150,10);
    blackInfo->setZValue(1);
    blackInfo->setDefaultTextColor(Qt::black);
    blackInfo->setFont(QFont("Arial",18));
    setBlackPointsInfo();
    addToScene(blackInfo);

    addToScene(bottomText);

    chess->addChessPiece();
}

void Game::setBlackPointsInfo()
{
    blackInfo->setPlainText("GRACZ CZARNY: " + QString::number(blackPoints));
}

void Game::setWhitePointsInfo()
{
    whiteInfo->setPlainText("GRACZ BIAŁY: " + QString::number(whitePoints));
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

void Game::placeInDeadPlace(ChessPieceView *piece)
{
    Side::Values side = piece->getChessModel()->getSide();
    if(side == Side::Values::White)
    {
        whiteDead.append(piece);
        KingView *g = dynamic_cast <KingView *>(piece);
        if(g) gameOver(side);
        displayDeadWhite();
    }
    else
    {
        blackDead.append(piece);
        KingView *g = dynamic_cast <KingView *>(piece);
        if(g) gameOver(side);
        displayDeadBlack();
    }
    alivePiece.removeAll(piece);
}

void Game::gameOver(Side::Values value)
{
    if(value == Side::Values::White)
    {
        bottomText->setPlainText("Gracz czarny wygrał!");
        blackPoints++;
        setBlackPointsInfo();
    }
    else
    {
        bottomText->setPlainText("Gracz biały wygrał!");
        whitePoints++;
        setWhitePointsInfo();
    }

    if(getFirstTurn() == Side::Values::White)
    {
        setFirstTurn(Side::Values::Black);
        topText->setPlainText("Kolej gracza czarnego");
    }
    else
    {
        setFirstTurn(Side::Values::White);
        topText->setPlainText("Kolej gracza białego");
    }

    alivePiece.clear();
    chess->reset();
}

Side::Values Game::getTurn()
{
    return turn;
}

void Game::setTurn(Side::Values value)
{
    turn = value;
}

Side::Values Game::getFirstTurn()
{
    return firstTurn;
}

void Game::setFirstTurn(Side::Values value)
{
    firstTurn = value;
    setTurn(value);
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

    topText->setPlainText("Kolej gracza " + turn);
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
    bottomText = new QGraphicsTextItem();
    bottomText->setPos(width()/2-100,860);
    bottomText->setZValue(4);
    bottomText->setDefaultTextColor(Qt::red);
    bottomText->setFont(QFont("",18));
    bottomText->setPlainText("CHECK!");
    bottomText->setVisible(false);
}

void Game::displayTurn()
{
    topText = new QGraphicsTextItem();
    topText->setPos(width()/2-100,10);
    topText->setZValue(1);
    topText->setDefaultTextColor(Qt::red);
    topText->setFont(QFont("Arial",18));
    topText->setPlainText("Kolej gracza białego");

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
