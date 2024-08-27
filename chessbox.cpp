#include "chessbox.h"
#include "game.h"
#include "king.h"
#include <QMessageBox>

extern Game *game;
ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(currentPiece == game->pieceToMove && currentPiece){

        currentPiece->mousePressEvent(event);
        return;
    }

    if(game->pieceToMove){
        //if same team
        if(this->getChessPieceColor() == game->pieceToMove->getSide())
            return;
        //removing the eaten piece
        QList <ChessBox *> movLoc = game->pieceToMove->moveLocation();
        //TO make sure the selected box is in move zone
        int check = 0;
        for(size_t i = 0, n = movLoc.size(); i < n;i++) {
            if(movLoc[i] == this) {
                check++;

            }
        }
        // if not prsent return
        if(check == 0)
            return;
        //change the color back to normal
        game->pieceToMove->decolor();
        //make the first move false applicable for pawn only
        game->pieceToMove->firstMove = false;
        //this is to eat or consume the enemy present inn the movable region
        if(this->getHasChessPiece()){
            this->currentPiece->setIsPlaced(false);
            this->currentPiece->setCurrentBox(NULL);
            game->placeInDeadPlace(this->currentPiece);

        }
        //changing the new stat and resetting the previous left region
        game->pieceToMove->getCurrentBox()->setHasChessPiece(false);
        game->pieceToMove->getCurrentBox()->currentPiece = NULL;
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        placePiece(game->pieceToMove);

        game->pieceToMove = NULL;
        //changing turn
        game->changeTurn();
        checkForCheck();
    }
    //Selecting couterpart of the chessPiece
    else if(this->getHasChessPiece())
    {
        this->currentPiece->mousePressEvent(event);
    }
}

void ChessBox::checkForCheck()
{
    int c = 0;
    QList <ChessPiece *> pList = game->alivePiece;

    for(size_t i = 0,n=pList.size(); i < n; i++ )
    {

        King * p = dynamic_cast<King *> (pList[i]);
        if(p) continue;

        pList[i]->moves();
        pList[i]->decolor();

        QList <ChessBox *> bList = pList[i]->moveLocation();

        for(size_t j = 0,n = bList.size(); j < n; j ++)
        {
            King * p = dynamic_cast<King *> (bList[j]->currentPiece);
            if(p)
            {
                if(p->getSide() == pList[i]->getSide()) continue;

                bList[j]->setColor(Qt::blue);
                pList[i]->getCurrentBox()->setColor(Qt::darkRed);

                if(!game->check->isVisible())
                    game->check->setVisible(true);
                else
                {
                    bList[j]->resetOriginalColor();
                    pList[i]->getCurrentBox()->resetOriginalColor();

                    if(p->getSide() == "WHITE")
                        QMessageBox::information(nullptr, "Game over", "Black Won       ");
                    else
                        QMessageBox::information(nullptr, "Game over", "White Won       ");
                    game->gameOver();
                }
                c++;

            }
        }


    }
    if(!c){
        game->check->setVisible(false);
        for(size_t i = 0,n=pList.size(); i < n; i++ )
            pList[i]->getCurrentBox()->resetOriginalColor();
    }
}

void ChessBox::placePiece(ChessPiece *piece)
{
    piece->setPos(
        x()+50- piece->pixmap().width()/2,
        y()+50-piece->pixmap().width()/2);

    piece->setCurrentBox(this);
    setHasChessPiece(true,piece);
    currentPiece = piece;
}

bool ChessBox::getHasChessPiece()
{
    return hasChessPiece;
}

void ChessBox::setHasChessPiece(bool value, ChessPiece *piece)
{
    hasChessPiece = value;
    if(value)
        setChessPieceColor(piece->getSide());
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
                black[k]->setIsPlaced(true);
                black[k]->firstMove = true;
                game->alivePiece.append(black[k++]);

            }
            if(i > 5) {

                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                white[h]->firstMove = true;
                game->alivePiece.append(white[h++]);

            }

        }
    }
}
