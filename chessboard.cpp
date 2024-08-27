#include "chessboard.h"
#include "chessbox.h"
#include "game.h"

extern Game *game;
ChessBoard::ChessBoard()
{
    setUpBlack();
    setUpWhite();
}

void ChessBoard::drawBoxes(int x,int y)
{
    QColor lightBoxColor = QColor(234, 236, 225);
    QColor darkBoxColor = QColor(86, 170, 102);

    int SHIFT = 100;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            ChessBox *box = new ChessBox();
            game->collection[i][j] = box;
            box->rowLoc = i;
            box->colLoc = j;
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                box->setOriginalColor(lightBoxColor);
            else
                box->setOriginalColor(darkBoxColor);
            game->addToScene(box);
        }
    }
}

void ChessBoard::addChessPiece() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessBox *box =game->collection[i][j];
            if(i < 2) {
                static int k;
                box->placePiece(black[k]);
                game->alivePiece.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i > 5) {
                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);
                game->addToScene(white[h++]);
            }

        }
    }
}


void ChessBoard::setUpWhite()
{
    //TODO NOW set up white pieces
}

void ChessBoard::setUpBlack()
{
    //TODO NOW set up black pieces
}
