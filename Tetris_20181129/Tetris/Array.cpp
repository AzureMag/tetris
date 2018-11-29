#include "stdafx.h"
#include <Windows.h>
#include "Block.h"
#include "Array.h"
#include <iostream>
#include <random>
#include <conio.h>
	
	void Array::SetGame() {	}
	Block* Array::MakeBlock() {
		Block* block = new Block();
		block->SetMiddleBlock();
		return block;
	}

	void Array::BlockArray(Block* block) {
		int x = block->FindX(); int y = block->FindY();
		m[x][y] = true;
		for (int i = 0; i<3; i++) {
			x = block->FindAnotherX(i); y = block->FindAnotherY(i);
			m[x][y] = true;
		}
	}//Make block to Array.
	void Array::BlockArrayErase(Block *block) {
		int x = block->FindX(); int y = block->FindY();
		m[x][y] = false;
		for (int i = 0; i < 3; i++) {
			x = block->FindAnotherX(i); y = block->FindAnotherY(i);
			m[x][y] = false;
		}
	}//Erase Block to Array

	void Array::BlockDown(Block* block, int i) {
		int x = block->FindX(); int y = block->FindY();
		BlockArrayErase(block);
		int a = FloorCheck(block, i);

		if (a == 1) {
			block->SetX(x+i);
			BlockArray(block);
		}
		else {
			BlockArray(block);
			BlockStop(block);
		}
		
	}
	void Array::BlockMove(Block* block, int LR) {
		int x = block->FindX(); int y = block->FindY(); int a, b;
		BlockArrayErase(block);
		switch (LR) {
		case LEFT:
			a = WallCheck(block, -1);
			b = -1;
			break;
			
		case RIGHT:
			a = WallCheck(block, 1);
			b = 1;
			break;
		}
		if (a == 1) {
			block->SetY(y+b);
		}
		BlockArray(block);
	}
	void Array::BlockRotate(Block* block) {
		
		BlockArrayErase(block);
		int blockinfrm = block->FindB();
		block->RotateBlock(1, blockinfrm);
		BlockArray(block);
	}

	int Array::WallCheck(Block *block, int i) {
		int x = block->FindX(); int y = block->FindY();
		if (m[x][y + i] || y + i < 0 || y + i > 9) {
			return 0;
		}
		for (int j = 0; j < 3; j++) {
			x = block->FindAnotherX(j); y = block->FindAnotherY(j);
			if (m[x][y + i] || y + i < 0 || y + i > 9) {
				return 0;
			}
		}
		return 1;
	}//This function is used to BlockMove and BlockRotate function.
	int Array::FloorCheck(Block *block, int i) {
		int x = block->FindX(); int y = block->FindY();
		if (m[x + i][y] || x == 17) {
			return 0;
		}
		for (int j = 0; j < 3; j++) {
			x = block->FindAnotherX(j); y = block->FindAnotherY(j);
			if (m[x + i][y] || x == 17) {
				return 0;
			}
		}
		return 1;
	}//This fuction is used to BlockDown and BlockRotate fuction.

	void Array::BlockStop(Block* block) {
		int x = block->FindX;
		line[x] += 1;
		for (int i = 0; i < 3; i++) {
			x = block->FindAnotherX(i);
			line[x] += 1;
		}
	}

	int Array::Delay(int speed) {
		Sleep(2000 / speed);
		return 1;
	}
	int Array::SetSpeed(int speed) {
		if (speed <= 10) {
			this->speed = speed;
			return 1;
		}
		else {
			return 0;
		}
	}
	int Array::Score(){}  
	int Array::LineClear(){}
	int Array::Input(){}
