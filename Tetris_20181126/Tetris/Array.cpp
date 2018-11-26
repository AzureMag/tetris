#include "stdafx.h"
#include "Block.h"
#include "Array.h"
#include <iostream>
#include <random>
#include <time.h>
#include <conio.h>
	
	void Array::Setgame() {	}
	Block* Array::MakeBlock() {
		Block* block = new Block();
		block->SetMiddleBlock();
		block->initXY();
		return block;
	}
	void Array::BlockArray(Block* block) {
		int i = 0; int x = block->FindX(); int y = block->FindY();
		m[x][y] = true;
		while (i < 3) {
			x = block->FindAnotherX(i); y = block->FindAnotherY(i);
			m[x][y] = true;
			i++;
		}
	}//Make block to Array.
	void Array::BlockArrayErase(Block *block) {
		int i = 0; int x = block->FindX(); int y = block->FindY();
		m[x][y] = false;
		while (i < 3) {
			x = block->FindAnotherX(i); y = block->FindAnotherY(i);
			m[x][y] = false;
			i++;
		}
	}//Erase Block to Array

	void Array::BlockDown(Block* block, int i) {
		BlockArrayErase(block);
		int x = block->FindX();
		x += i;
		block->SetX(x);
		BlockArray(block);
	}
	void Array::BlockMove(Block* block, int LR) {
		BlockArrayErase(block);
		int x = block->FindX();
		int y= block->FindY();
		switch (LR) {
		case LEFT:
			y--;
			if (y < 0) {
				y++;
				break;
			}
			//you can't move the block to left because y isn't minus.
			if (m[x][y]) {
				y++;
				break;
			}
			//you can't move the block to left because, at left, there is block.
			//modify this
			block->SetY(y);
			break;

		case RIGHT:
			y++;
			if (y > 9) {
				y--;
				break;
			}
			// you can't move the block to right because y is smaller than 10.
			if (m[x][y]) {
				y++;
				break;
			}
			//you can't move the block to right because, at right, there is block.
			//modify this
			block->SetY(y);
			break;
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

	}

	//Modify BlockDown, BlockMove, BlockRotate function
	//Add other function(Input, time)