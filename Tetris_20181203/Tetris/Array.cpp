#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <random>
#include <conio.h>
#include "Block.h"
#include "Array.h"
#include <time.h>

	//private:
	void Array::BlockArray(Block* block) {
		int x = block->FindX(); int y = block->FindY();
		m[x][y] = true;
		for (int i = 0; i<3; i++) {
			x = block->FindAnotherX(i); y = block->FindAnotherY(i);
			m[x][y] = true;
		}
	}
	void Array::BlockArrayErase(Block *block) {
		int x = block->FindX(); int y = block->FindY();
		m[x][y] = false;
		for (int i = 0; i < 3; i++) {
			x = block->FindAnotherX(i); y = block->FindAnotherY(i);
			m[x][y] = false;
		}
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
	}
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
	}

	//public:
	Block* Array::MakeBlock() {
		Block* block = new Block();
		return block;
	}
	bool Array::BlockDown(Block* block, int i) {
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
			return true;
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
	void Array::BlockStop(Block* block) {
		int x = block->FindX;
		line[x] += 1;
		for (int i = 0; i < 3; i++) {
			x = block->FindAnotherX(i);
			line[x] += 1;
		}
	}

	void Array::InitScore() {
		this->score = 0;
	}
	int Array::LineScore(int line){
		switch (line) {
		case 1:
			this->score += 50; //50
			return 1;
		case 2:
			this->score += 120; //60
			return 2;
		case 3:
			this->score += 210; //70
			return 3;
		case 4:
			this->score += 320;
			return 4;
		}
	} 
	int Array::LineClear(int x){
		for (x; x > 3; x--) {
			this->line[x] = this->line[x - 1];
			for (int i = 0; i < 9; i++) {
				this->m[x][i] = { false };
				this->m[x][i] = this->m[x - 1][i];
			}
		}

	}
	int Array::LineStack(int x) {
		return this->line[x];
	}
	int Array::ReturnScore(){
		return this->score;
	}

	void Array::InitSpeed(){
		this->speed = 1;
	}
	int Array::Delay(int speed) {
		float Gtime = 2000 / speed;
		Sleep(Gtime);
		this->Gtime = Gtime;
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
	int Array::ReturnSpeed() {
		return this->speed;
	}
	void Array::InitTime(){
		this->Gtime = 0;
	}
	float Array::ReturnTime() {
		return this->Gtime;
	}
	
	int Array::Input(){
		int key;
		if (kbhit()) {
			key = getch();
			return key;
		}
		return 0;
	}
