#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32

class arr {
private:
	int score;
	float speed;
	bool m[12][10];
	void Setgame() {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 10; j++) {
				m[i][j] = false;
			}
		}

	}//Game start
	 //Game set

	void Blockshape(int i, int x, int y, int rotate) {

	}
	int Downblock() {

	}
	int Moveblock() {

	}
	int RotateBlock() {}
public:

};