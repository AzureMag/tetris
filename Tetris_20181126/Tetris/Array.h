#pragma once

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32


class Array {
private:
	static Block* block;
	int score;
	float speed;
	bool m[12][10] = {false};

	void Setgame(); //initialize game

	Block* MakeBlock();
	void BlockArrayErase(Block * block);
	void BlockArray(Block * block);
	
	void BlockDown(Block* block, int i);
	void BlockMove(Block* block, int LR);
	void BlockRotate(Block* block);
	void BlockStop(Block * block);
public:

};