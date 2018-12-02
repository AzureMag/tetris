#pragma once

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32

class Array {
private:
	int score; 
	float Gtime;
	int speed = 1;
	bool m[18][10] = {false};
	int line[18] = { 0 }; //This is line, if this array member is 10, m array member is erase, and line member is -1 line.

	void BlockArray(Block * block);//Make block to Array.
	void BlockArrayErase(Block * block);//Erase Block to Array
	
	int WallCheck(Block *block, int i);//This function is used to BlockMove and BlockRotate function.
	int FloorCheck(Block *block, int i);//This fuction is used to BlockDown and BlockRotate fuction.
	//AaB's fuction
	//Two fuctions above this line return 1 when you can move the block or 0 when you can't move the block. 

public:
	//Control block
	Block * MakeBlock();
	bool BlockDown(Block* block, int i);
	void BlockMove(Block* block, int LR);
	void BlockRotate(Block* block);
	void BlockStop(Block * block);

	//Line and score
	void InitScore();
	int LineClear(int x);
	int LineStack(int x);
	int ReturnScore();
	int LineScore(int line);

	//time and speed
	void InitSpeed();
	int Delay(int speed);
	int SetSpeed(int speed);
	int ReturnSpeed();
	void InitTime();
	float ReturnTime();

	//input
	int Input(); 
				 //In while, you can use this function.
				 //Modify BlockRotate function
				 //Add other function(Input, time)

};