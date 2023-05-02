#include "Board.h"


Board::Board(Pieces* pPieces, int pScreenHeight)
{
	mScreenHeight = pScreenHeight;

	mPieces = pPieces;

	InitBoard();
}


void Board::InitBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
		for (int j = 0; j < BOARD_HEIGHT; j++)
			mBoard[i][j] = POS_FREE;
}

// Store the blocks in the board
void Board::StorePiece(int pX, int pY, int pPiece, int pRotation)
{
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{
			if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
				mBoard[i1][j1] = POS_FILLED;
		}
	}
}



//Check if the game is over

bool Board::IsGameOver()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (mBoard[i][0] == POS_FILLED) return true;
	}

	return false;
}



//Delete a line of the board by moving all above lines down
void Board::DeleteLine(int pY)
{
	// Moves all the upper lines one row down
	for (int j = pY; j > 0; j--)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			mBoard[i][j] = mBoard[i][j - 1];
		}
	}
}


//Delete all the lines that are filled

void Board::DeletePossibleLines()
{
	int ClearedLines = 0;
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		int i = 0;
		while (i < BOARD_WIDTH)
		{
			if (mBoard[i][j] != POS_FILLED) break;
			i++;
		}

		if (i == BOARD_WIDTH)
		{
			DeleteLine(j);
			ClearedLines++;
		}
	}
	mStats.UpdateLineClears(ClearedLines);
	mStats.UpdateTetrises(ClearedLines);
	mStats.AddScore(ClearedLines);
}


// Check if the block is already filled
bool Board::IsFreeBlock(int pX, int pY)
{
	if (mBoard[pX][pY] == POS_FREE) return true; else return false;
}




int Board::GetXPosInPixels(int pPos)
{
	return  ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE));
}



int Board::GetYPosInPixels(int pPos)
{
	return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}



// Check if the piece can be stored at this position without any collision

bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation)
{
	// Check the piece within the board
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		if (i1 < 0)
		{
			i1 = BOARD_WIDTH - 1;
		}
		else if (i1 > BOARD_WIDTH - 1)
		{
			i1 = 0;
		}
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{
			// Check if the piece is outside the limits of the board
			if (i1 < 0 ||
				i1 > BOARD_WIDTH - 1 ||
				j1 > BOARD_HEIGHT - 1)
			{
				if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
					return 0;
			}

			// Check the piece with prelaid blocks
			if (j1 >= 0)
			{
				if ((mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) &&
					(!IsFreeBlock(i1, j1)))
					return false;
			}
		}
	}

	return true;
}
