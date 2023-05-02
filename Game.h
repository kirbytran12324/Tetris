#ifndef _GAME_
#define _GAME_

// ------ Includes -----

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>
#include <cstdlib>
#include <cassert>

// ------ Defines -----

#define WAIT_TIME 500			// Number of milliseconds that the piece remains before going 1 block down */ 

class Game
{
public:
    Game(Board* pBoard, Pieces* pPieces, int pScreenHeight);

    void CreateNewPiece();
    int mPosX, mPosY;				// Position of the piece that is falling down
    int mPiece, mRotation;			// Kind and rotation the piece that is falling down
    int mBag[7];                        // Array to store the pieces in the bag
    int mBagIndex;                      // Index to keep track of the current position in the bag

private:
    int mScreenHeight;				// Screen height in pixels
    int mNextPosX, mNextPosY;		// Position of the next piece
    int mNextPiece, mNextRotation;	// Kind and rotation of the next piece
    int mHoldPosX, mHoldPosY;		// Position of the held piece
    int mHoldPiece, mHoldRotation;	// Kind and rotation of the held piece
    Board* mBoard;
    Pieces* mPieces;
    void FillRandomizedBag();           // Function to fill the bag with random pieces
    int GetRandomPiece();               // Function to get the next piece from the bag    
    void InitGame();                    
    int GetRand(int a, int b);
};

#endif //_GAME_
