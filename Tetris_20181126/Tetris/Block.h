#pragma once

class Block {
private:
	int BlockInfrm = 0;												//block's imformation	
	int x; int y;													//Middle block's location.
	int AnotherX[3], AnotherY[3];									//Another block's location(Middle block's location is 0,0)
public:
	int FindB();
	int FindX();
	int FindY();
	//a is 0 to 2 //output is real location
	int FindAnotherX(int a);
	int FindAnotherY(int a);

	void initXY();
	void SetX(int x);
	void SetY(int y);
	void SetXY(int x, int y);
	void SetBlockInfrm(int BlockInfrm);
	void SetOtherBlock(int BlockInfrm);
	
	void SetMiddleBlock(); 											//if you use this function, you 'must' use "srand(time(NULL));"
	void SetMiddleBlock(int BlockInfrm);

	void RotateBlock(int rotate, int BlockInfrm);					//To Rotation AnotherX or Y is changed.
																	//-90 degree rotation transformation
																	//To Rotation AnotherX or Y is changed.
	Block() {
		SetMiddleBlock();
	}



};