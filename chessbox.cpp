#include "chessbox.h"
#include "game.h"
#include "kingview.h"
#include <QMessageBox>

extern Game *game;
ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasChessPiece(false);
    setChessPieceColor("NONE");
    currentPiece = NULL;
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(deselect(event)) return;

    if(game->pieceToMove)
    {
        if(sameTeam()) return;
        if(!selectedBoxIsInMoveZone()) return;

        if(this->getHasChessPiece()) consumePiece();

        movePiece();

        game->changeTurn();
        checkForCheck();
    }
    else if(this->getHasChessPiece())
    {
        select(event);
    }
}

bool ChessBox::deselect(QGraphicsSceneMouseEvent *event)
{
    if(currentPiece == game->pieceToMove && currentPiece)
    {
        currentPiece->mousePressEvent(event);
        return true;
    }

    return false;
}

void ChessBox::select(QGraphicsSceneMouseEvent *event)
{
    this->currentPiece->mousePressEvent(event);
}

bool ChessBox::sameTeam()
{
    if(this->getChessPieceColor() == game->pieceToMove->getChessModel()->getSideAsString())
        return true;

    return false;
}

bool ChessBox::selectedBoxIsInMoveZone()
{
    QList <ChessBox *> movLoc = game->pieceToMove->getChessModel()->moveLocation();

    int check = 0;
    for(size_t i = 0, n = movLoc.size(); i < n;i++) {
        if(movLoc[i] == this) {
            check++;
        }
    }

    if(check == 0)
        return false;

    return true;
}

void ChessBox::consumePiece()
{
    this->currentPiece->getChessModel()->setIsPlaced(false);
    this->currentPiece->getChessModel()->setCurrentBox(NULL);
    game->placeInDeadPlace(this->currentPiece);
}

void ChessBox::movePiece()
{
    game->pieceToMove->decolor();
    game->pieceToMove->getChessModel()->firstMove = false;
    game->pieceToMove->getChessModel()->getCurrentBox()->setHasChessPiece(false);
    game->pieceToMove->getChessModel()->getCurrentBox()->currentPiece = NULL;
    game->pieceToMove->getChessModel()->getCurrentBox()->resetOriginalColor();
    placePiece(game->pieceToMove);

    game->pieceToMove = NULL;
}

void ChessBox::checkForCheck()
{
    int c = 0;
    QList <ChessPieceView *> pList = game->alivePiece;

    for(size_t i = 0,n=pList.size(); i < n; i++ )
    {
        KingView * p = dynamic_cast<KingView *> (pList[i]);
        if(p) continue;

        pList[i]->getChessModel()->moves();
        pList[i]->decolor();

        QList <ChessBox *> bList = pList[i]->getChessModel()->moveLocation();

        for(size_t j = 0,n = bList.size(); j < n; j ++)
        {
            KingView * p = dynamic_cast<KingView *> (bList[j]->currentPiece);
            if(p)
            {
                if(p->getChessModel()->getSide() == pList[i]->getChessModel()->getSide()) continue;

                bList[j]->setColor(Qt::blue);
                pList[i]->getChessModel()->getCurrentBox()->setColor(Qt::darkRed);

                if(!game->bottomText->isVisible())
                    game->bottomText->setVisible(true);
                else
                {
                    bList[j]->resetOriginalColor();
                    pList[i]->getChessModel()->getCurrentBox()->resetOriginalColor();
                    game->gameOver(p->getChessModel()->getSide());
                }
                c++;

            }
        }


    }
    if(!c){
        game->bottomText->setVisible(false);
        for(size_t i = 0,n=pList.size(); i < n; i++ )
            pList[i]->getChessModel()->getCurrentBox()->resetOriginalColor();
    }
}

void ChessBox::placePiece(ChessPieceView *piece)
{
    piece->setPos(
        x()+50- piece->pixmap().width()/2,
        y()+50-piece->pixmap().width()/2);

    piece->getChessModel()->setCurrentBox(this);
    setHasChessPiece(true,piece);
    currentPiece = piece;
}

bool ChessBox::getHasChessPiece()
{
    return hasChessPiece;
}

void ChessBox::setHasChessPiece(bool value, ChessPieceView *piece)
{
    hasChessPiece = value;
    if(value)
        setChessPieceColor(piece->getChessModel()->getSideAsString());
    else
        setChessPieceColor("NONE");
}

QString ChessBox::getChessPieceColor()
{
    return chessPieceColor;
}

void ChessBox::setChessPieceColor(QString value)
{
    chessPieceColor = value;
}

void ChessBox::resetOriginalColor()
{
    setColor(originalColor);
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

void ChessBoard::reset() {
    int k = 0; int h = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessBox *box =game->collection[i][j];
            box->setHasChessPiece(false);
            box->setChessPieceColor("NONE");
            box->currentPiece = NULL;
            if(i < 2) {

                box->placePiece(black[k]);
                black[k]->getChessModel()->setIsPlaced(true);
                black[k]->getChessModel()->firstMove = true;
                game->alivePiece.append(black[k++]);

            }
            if(i > 5) {

                box->placePiece(white[h]);
                white[h]->getChessModel()->setIsPlaced(true);
                white[h]->getChessModel()->firstMove = true;
                game->alivePiece.append(white[h++]);

            }

        }
    }
}
