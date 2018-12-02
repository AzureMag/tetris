#pragma once

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32

class InGame {
private:
	Array * arr = new Array();
	Block* block;
	int speed, LineClearStack; //lineclearstack is, if you stop the block and clear the line, number of cleared lines
	bool end;
	int score;
	float Ptime;
public:
	void Game();
	void Setting();
	void Menu();
};