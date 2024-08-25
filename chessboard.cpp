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


void ChessBoard::setUpWhite()
{
    //TODO set up white pieces
}

void ChessBoard::setUpBlack()
{
    //TODO set up black pieces
}
