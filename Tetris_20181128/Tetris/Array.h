#pragma once

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32


class Array {
private:
	static Block* block;
	int score, time;
	float speed = 1;
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

	void BlockStop(Block * block);
public:

};