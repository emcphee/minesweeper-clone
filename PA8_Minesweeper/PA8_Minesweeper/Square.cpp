#include "Square.h"


Square::Square() {
	mFlagged = false;
	mHidden = true;
	mIsBomb = false;
	mBombsAdjacent = 0;
}


// return -1 if game ends, 0 if nothing, 1 if calls recursive reveal on a 0 square 
//2 if it just gets unhidden

int Square::mLeftClicked() {
	// if a square is left clicked or already not hidden,
	// function should exit with 0
	if (mFlagged == true || mHidden == false) {
		return 0;
	}
	// if a bomb, game should end by returning -1
	if (mIsBomb) {
		return -1;
	}
	// if square is a blank, it should be unhidden and unhide adjacent squares
	if (mBombsAdjacent == 0) {
		// return signal for recursive reveal
		mHidden = false;
		return 1;
	}
	// at this point the square must be a number
	// so it reveals and returns 2 to signal the display to unhide
	mHidden = false;
	return 2;
}

//returns 0 for do nothing, 1 for turn flag on, 2 for turn flag off
int Square::mRightClicked() {
	if (!mHidden) {
		return 0;
	}
	if (mFlagged) {
		mFlagged = false;
		return 1;
	}
	else {
		mFlagged = true;
		return 2;
	}
}