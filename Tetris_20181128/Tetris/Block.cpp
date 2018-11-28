#include "stdafx.h"
#include "Block.h"
#include <random>
#include <time.h>

	int Block::FindB() {
		return BlockInfrm;
	}
	int Block::FindX() {
		return x;
	}
	int Block::FindY() {
		return y;
	}

	int Block::FindAnotherX(int a) {
		return x + AnotherX[a];
	}
	int Block::FindAnotherY(int a) {
		return y + AnotherY[a];
	}

	void Block::initXY() {
		SetXY(2, 4);
	}
	void Block::SetX(int x){
		this->x = x;
	}
	void Block::SetY(int y){
		this->y = y;
	}
	void Block::SetXY(int x, int y) {
		this->x = x; this->y = y;
	}
	void Block::SetBlockInfrm(int BlockInfrm){
		this->BlockInfrm = BlockInfrm;
	}
	void Block::SetOtherBlock(int BlockInfrm) {
		switch (BlockInfrm) {
		case 1:
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = 1;
			break;

		case 2:
			AnotherX[0] = -1; AnotherY[0] = -1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = 0; AnotherY[2] = 1;
			break;
		case  3:
			AnotherX[0] = -1; AnotherY[0] = 1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = 0; AnotherY[2] = 1;
			break;
		case  4:
			AnotherX[0] = 0; AnotherY[0] = -1;
			AnotherX[1] = 0; AnotherY[1] = 1;
			AnotherX[2] = 0; AnotherY[2] = 2;
			break;
		case 5:
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = -1; AnotherY[2] = 0;
			break;
		case 6:
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = -1;
			break;
		case 7:
			AnotherX[0] = 0; AnotherY[0] = -1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = 1;
			break;
		}
	}
	void Block::SetMiddleBlock() {
		int a = rand() % 7 + 1; 
		initXY();
		SetBlockInfrm(a);
		SetOtherBlock(a);
	}
	void Block::SetMiddleBlock(int BlockInfrm) {
		initXY();
		SetBlockInfrm(BlockInfrm);
		SetOtherBlock(BlockInfrm);
	}

	void Block::RotateBlock(int rotate, int BlockInfrm) {
		if (BlockInfrm > 1) {
			int c = 0;
			rotate = rotate % 4;
			if (rotate != 0) {
				for (int i = 0; i < rotate; i++) {
					for (int j = 0; j < 3; j++) {
						c = AnotherX[j]; AnotherX[j] = AnotherY[j]; AnotherY[j] = -c; 
					}
				}
			}
		}
	}					

//block information
/*
1. #*  2. *   3.   *
   **     *#*    *#*
4. *#** 5. *  6.  #*
          *#*    **
7.*#
   **

# is Middleblock's location
*/

//block class completed!