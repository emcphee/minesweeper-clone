#pragma once

class Board;
class Square
{
public:
	bool mFlagged;
	bool mHidden;
	bool mIsBomb;
	unsigned short int mBombsAdjacent;

	friend class Board;
	Square();
	int mLeftClicked();
	int mRightClicked();
};

