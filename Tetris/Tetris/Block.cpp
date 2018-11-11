#include "stdafx.h"
#include <random>
#include <time.h>


class Block {
private:
	int BlockInfrm = 0;			//block's imformation	
	int x; int y;		//Middle block's location.
	int AnotherX[3], AnotherY[3];	//Another block's location(Middle block's location is 0,0)
public:
	int FindB() {
		return BlockInfrm;
	}
	int FindX() {
		return x;
	}
	int FindY() {
		return y;
	}
						//a is 0 to 2 //output is real location
	int FindAnotherX(int a) {
		return x + AnotherX[a];
	}
	int FindAnotherY(int a) {
		return y + AnotherY[a];
	}

	void initXY() {
		SetXY(2, 4);
	}
	void SetXY(int x, int y) {
		this->x = x; this->y = y;
	}
	void SetBlockInfrm(int BlockInfrm){
		this->BlockInfrm = BlockInfrm;
	}
	void SetOtherBlock(int BlockInfrm) {
		if (BlockInfrm == 1) {
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = 1;
		}
		else if (BlockInfrm == 2) {
			AnotherX[0] = -1; AnotherY[0] = -1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = 0; AnotherY[2] = 1;
		}
		else if (BlockInfrm == 3) {
			AnotherX[0] = -1; AnotherY[0] = 1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = 0; AnotherY[2] = 1;
		}
		else if (BlockInfrm == 4) {
			AnotherX[0] = 0; AnotherY[0] = -1;
			AnotherX[1] = 0; AnotherY[1] = 1;
			AnotherX[2] = 0; AnotherY[2] = 2;
		}
		else if (BlockInfrm == 5) {
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = -1; AnotherY[2] = 0;
		}
		else if (BlockInfrm == 6) {
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = -1;
		}
		else {
			AnotherX[0] = 0; AnotherY[0] = -1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = 1;
		}
	}
	void SetMiddleBlock() {
		int a = rand() % 7 + 1; //if you use this function, you must use "srand(time(NULL));"
		SetBlockInfrm(a);
		SetOtherBlock(a);
	}
	void SetMiddleBlock(int BlockInfrm) {
		initXY();
		SetBlockInfrm(BlockInfrm);
		SetOtherBlock(BlockInfrm);
	}

	void RotateBlock(int rotate, int BlockInfrm) {
		if (BlockInfrm > 1) {
			int c = 0;
			rotate = rotate % 4;
			if (rotate != 0) {
				for (int i = 0; i < rotate; i++) {
					for (int j = 0; j < 3; j++) {
						c = AnotherX[j]; AnotherX[j] = AnotherY[j]; AnotherY[j] = -c; //-90 degree rotation transformation
					}
				}
			}
		}
	}					//To Rotation AnotherX or Y is changed.

	Block() {
		SetMiddleBlock();

	}
};
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