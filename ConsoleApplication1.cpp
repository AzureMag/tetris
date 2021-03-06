// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32

//설명
//클래스를 어떻게 나누냐.
//블럭 클래스-> 배열 클래스-> 게임 화면 클래스]
//블럭 클래스: 7개의 블럭을 랜덤으로 생성하고, 그 블럭에 따라 값을 배열 클래스에 전달.
//배열 클래스: 받은 블럭을 키보드에 입력되는 값에 따라서 블럭의 값을 조절하고, 그 값을 게임 화면 클래스에 전달.
//게임 화면 클래스: 배열 클래스에 값을 받아서 화면에 표시

using namespace std;

class Block {
private:
	int b = 0;			//block에 대한 정보	
	int rotate = 0;		//block이 돈 정도
	int x; int y;		//중심 block(Middle block)의 위치.
	int AnotherX[3], AnotherY[3];	//나머지 block의 위치(중심 block의 위치를 0,0으로 잡은 경우 상대적 위치)
public:
	int FindB() {
		return b;
	}					//block에 대한 정보 반환
	int FindX() {
		return x;
	}					//x값 반환
	int FindY() {
		return y;
	}					//y값 반환
	//a는 0~2까지 //출력할 때는 실제 좌표를 출력
	int FindAnotherX(int a){
		return x + AnotherX[a];
	}
	int FindAnotherY(int a){
		return y + AnotherY[a];
	}

	void initXY() { 
		SetXY(2, 4);
	}
	void SetXY(int x, int y) {
		this->x = x; this->y = y;
	}//x값 설정, y값 설정(중심 block)

	void SetOtherBlock(int b) {
		//중심 block의 위치를 0,0으로 잡은 경우 다른 블럭의 좌표를 넣는다.
		//block값에 따라 좌표가 달라짐
		if (b == 1) {
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = 1;
		}
		else if (b == 2) {
			AnotherX[0] = -1; AnotherY[0] = -1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = 0; AnotherY[2] = 1;
		}
		else if (b == 3) {
			AnotherX[0] = -1; AnotherY[0] = 1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = 0; AnotherY[2] = 1;
		}
		else if (b == 4) {
			AnotherX[0] = 0; AnotherY[0] = -1;
			AnotherX[1] = 0; AnotherY[1] = 1;
			AnotherX[2] = 0; AnotherY[2] = 2;
		}
		else if (b == 5) {
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 0; AnotherY[1] = -1;
			AnotherX[2] = -1; AnotherY[2] = 0;
		}
		else if (b == 6) {
			AnotherX[0] = 0; AnotherY[0] = 1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = -1;
		}
		else {
			AnotherX[0] = 0; AnotherY[0] = -1;
			AnotherX[1] = 1; AnotherY[1] = 0;
			AnotherX[2] = 1; AnotherY[2] = 1;
		}
	}
	void SetMiddleBlock() {
		this->b = rand() % 7 + 1; //사용할 시, srand(time(NULL));를 반드시 넣을 것.
		//나머지 block들 설정
		int b = this->FindB();
		SetOtherBlock(b);
	}					//block값 설정
	void SetMiddleBlock(int b){
		initXY();
		this->b = b;
		SetOtherBlock(b);
	}

	void RotateBlock(int rotate) {
		int c = 0;
		rotate = rotate % 4;
		if (rotate != 0) {
			for (int i = 0; i < rotate; i++) {
				for (int j = 0; j < 3; j++) {
					c = ax[j]; ax[j] = ay[j]; ay[j] = -c; //-90도 회전변환 rotate수 = 회전 수
				}
			}
		}
	}					//회전값 설정

	Block(){
		SetMiddleBlock();
		
	}
};
//block 모양
/*
1. #*  2. *   3.   *
   **     *#*    *#*
4. *#** 5. *  6.  #*
          *#*    **
7.*#
   **

   #의 위치가 중심 block의 위치
*/

//block class completed!

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

	}//게임 처음 시작할 때.
	//게임 셋

	void Blockshape(int i, int x, int y, int rotate) {
		
	}
	int Downblock() {

	}
	int Moveblock() {

	}
	int RotateBlock(){}
public:

};

class InGame {

};


int main()
{

}

