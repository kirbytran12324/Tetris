#ifndef _BOARD_
#define _BOARD_

// ------ Includes -----

#include "Pieces.h"
#include "Stats.h"

// ------ Defines -----

#define BOARD_LINE_WIDTH 6			
#define BLOCK_SIZE 16				
#define BOARD_POSITION 320			
#define BOARD_WIDTH 10				// Board width in blocks 
#define BOARD_HEIGHT 20				// Board height in blocks
#define MIN_VERTICAL_MARGIN 20			
#define MIN_HORIZONTAL_MARGIN 20	
#define PIECE_BLOCKS 5				// Number of horizontal and vertical blocks of a matrix piece


class Board
{
public:

	Board(Pieces* pPieces, int pScreenHeight);
	int GetXPosInPixels(int pPos);
	int GetYPosInPixels(int pPos);
	bool IsFreeBlock(int pX, int pY);
	bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);
	void StorePiece(int pX, int pY, int pPiece, int pRotation);
	void DeletePossibleLines();
	bool IsGameOver();

private:

	enum { POS_FREE, POS_FILLED };			
	int mBoard[BOARD_WIDTH][BOARD_HEIGHT];	
	Pieces* mPieces;
	Stats mStats;
	int mScreenHeight;

	void InitBoard();
	void DeleteLine(int pY);
};
#endif _BOARD_