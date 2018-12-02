#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <random>
#include <conio.h>
#include <cstdio>
#include "Block.h"
#include "Array.h"
#include "InGame.h"
#include <time.h>

void InGame::Game() {
	srand(time(NULL));
	arr->InitScore(); arr->InitTime();
	speed = arr->ReturnSpeed();
	while (1) {
		block = arr->MakeBlock();
		//1. make a block
		end = false;
		LineClearStack = 0;
		//2. block is down //control block
		while (1) {
			int key = arr->Input();
			switch (key) {
			case LEFT:
				arr->BlockMove(block, LEFT);
				break;
			case RIGHT:
				arr->BlockMove(block, RIGHT);
				break;
			case DOWN:
				arr->BlockDown(block, 1);
				break;
			case SPACE:
				//arr->BlockRotate(block);
				break;
			}
			arr->Delay(speed);
			end = arr->BlockDown(block, 1);
			if (end) {
				break;
			}
		}
		//3. block stop.
		for (int i = 17; i > 3; i--) {
			int iLS = arr->LineStack(i);
			if (iLS == 10) {
				arr->LineClear(i);
			}
			LineClearStack++;
		}
		//4. line check and clear
		if (LineClearStack > 0) {
			arr->LineScore(LineClearStack);
		}
		//5. As lineclearstack, scores are given. 
		if (arr->LineStack(2) > 0) {
			break;
		}
		//6. if blocks are so many, this game is stop, else Game will be continued. 
	}

	printf("Game Over!\n");
	Sleep(3500);
	printf("Your score is %d, and your playtime is %0.1f. \n", score, Ptime);
	Sleep(3000);
	printf("See you next time!\n");
	printf("If you press any buttons, this game stop!\n");
	scanf_s("%d",&score,sizeof(int));
}
void InGame::Setting() {

}
void InGame::Menu() {

}