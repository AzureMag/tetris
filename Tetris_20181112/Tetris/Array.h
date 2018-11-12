#pragma once

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32


class Array {
private:
	int score;
	float speed;
	bool m[12][10];
	void Setgame();//initialize game
	void Blockshape(int i, int x, int y, int rotate);
	int Downblock();
	int Moveblock();
	int RotateBlock();
public:

};