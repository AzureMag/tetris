#pragma once

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32


class Array {
private:
	static Block* block;
	int score, time;
	int speed = 1;
	bool m[18][10] = {false};
	int line[18] = { 0 }; //This is line, if this array member is 10 m array member is erase, and line member is -1 line.

	void SetGame(); //initialize game
	//Game

	Block* MakeBlock();
	//Block

	void BlockArrayErase(Block * block);
	void BlockArray(Block * block);
	//Array

	void BlockDown(Block* block, int i);
	void BlockMove(Block* block, int LR);
	void BlockRotate(Block* block);
	//Array and Block
	
	int WallCheck(Block *block, int i);
	int FloorCheck(Block *block, int i);
	//AaB's fuction
	//Two fuctions above this line return 1 when you can move the block or 0 when you can't move the block. 

	void BlockStop(Block * block);

	int Delay(int speed);

	int SetSpeed(int speed);

	int Score();

	int LineClear();

	int Input();

	//Modify BlockRotate function
	//Add other function(Input, time)
public:

};