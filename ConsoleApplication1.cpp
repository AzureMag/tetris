// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>

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
	int x; int y;		//중심 block의 위치.
public:
	int FindB() {
		return b;
	}					//block에 대한 정보 반환
	int FindRotate() {
		return rotate;
	}					//block 회전 정보 반환
	int FindX() {
		return x;
	}					//x값 반환
	int FindY() {
		return y;
	}					//y값 반환

	void SetB(int b) {
		this->b = b;
	}					//block값 설정
	void SetX(int x, int y) {
		this->x = x; this->y = y;
	}

	void SetX(int x) {
		this->x = x;
	}					//x값 설정
	void SetY(int y) {
		this->y = y;
	}					//y값 설정
	void SetRotate(int rotate) {
		this->rotate += rotate;
		if (rotate == 4) {
			this->rotate = 0;
		}
	}					//회전값 설정

	Block(){
			this->b = rand() % 7 + 1;//사용할 시, srand(time(NULL));를 반드시 넣을 것.
		/*
		1. **  2. *   3.   *
		   **     ***    ***
		4. **** 5. *  6. **
		          ***     **
		7.**
		   **
		
		*/
	}
};

class abc {
private:
	int a1, b1, a2, b2, a3, b3;
	bool m[12][10];
	void Setgame() {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 10; j++) {
				m[i][j] = false;
			}
		}

	}//게임 처음 시작할 때.
	//게임 셋

	void RB(int &a, int &b, int rotate) {
		if (rotate != 0) {
			for (int i = 0; i < rotate; i++) {
				int c;
				c = a; a = -b; b = c;
			}
		}
	}//참조자, 포인터 찾아볼것
	void RB1(int x, int y, int a, int b) {
		m[x+a][y+b] = true;
		//각 블럭의 위치
		//회전과 x,y에 따라 값을 바꾸는 함수,
	}
	void FB(int x, int y, int a, int b) {
		m[x + a][y + b] = false;
	} //이전 블럭을 지우기
	//block의 위치, 회전 정도를 결정

	void Blockshape(int i, int x, int y, int rotate) {
		if (i == 1) {
			a1 = 0, b1 = 1;
			a2 = 1, b2 = 0;
			a3 = 1, b3 = 1;

			FB(x, y, a1, b1); FB(x, y, a2, b2); FB(x, y, a3, b3);
			RB1(x, y, a1, b1); RB1(x, y, a2, b2); RB1(x, y, a3, b3);

		}
		else if (i == 2) {
			a1 = -1, b1 = -1;
			a2 = -1, b2 = 0;
			a3 = 1, b3 = 0;

			FB(x, y, a1, b1); FB(x, y, a2, b2); FB(x, y, a3, b3);
			RB(a1, b1, rotate); RB(a2, b2, rotate); RB(a3, b3, rotate);
			RB1(x,y,a1,b1); RB1(x,y,a2,b2); RB1(x,y,a3,b3);

		}
		else if (i == 3) {
			a1 = 1, b1 = -1;
			a2 = -1, b2 = 0;
			a3 = 1, b3 = 0;

			FB(x, y, a1, b1); FB(x, y, a2, b2); FB(x, y, a3, b3);
			RB(a1, b1, rotate); RB(a2, b2, rotate); RB(a3, b3, rotate);
			RB1(x, y, a1, b1); RB1(x, y, a2, b2); RB1(x, y, a3, b3);
				
		}
		else if (i == 4) {
			a1 = -1, b1 = -1;
			a2 = -1, b2 = 0;
			a3 = 1, b3 = 0;

			FB(x, y, a1, b1); FB(x, y, a2, b2); FB(x, y, a3, b3);
			RB(a1, b1, rotate); RB(a2, b2, rotate); RB(a3, b3, rotate);
			RB1(x, y, a1, b1); RB1(x, y, a2, b2); RB1(x, y, a3, b3);
			
		}
		else if (i == 5) {
			a1 = -1, b1 = -1;
			a2 = -1, b2 = 0;
			a3 = 1, b3 = 0;

			FB(x, y, a1, b1); FB(x, y, a2, b2); FB(x, y, a3, b3);
			RB(a1, b1, rotate); RB(a2, b2, rotate); RB(a3, b3, rotate);
			RB1(x, y, a1, b1); RB1(x, y, a2, b2); RB1(x, y, a3, b3);
							
		}
		else if (i == 6) {
			a1 = -1, b1 = -1;
			a2 = -1, b2 = 0;
			a3 = 1, b3 = 0;

			FB(x, y, a1, b1); FB(x, y, a2, b2); FB(x, y, a3, b3);
			RB(a1, b1, rotate); RB(a2, b2, rotate); RB(a3, b3, rotate);
			RB1(x, y, a1, b1); RB1(x, y, a2, b2); RB1(x, y, a3, b3);
			
		}
		else {
			a1 = -1, b1 = -1;
			a2 = -1, b2 = 0;
			a3 = 1, b3 = 0;

			FB(x, y, a1, b1); FB(x, y, a2, b2); FB(x, y, a3, b3);
			RB(a1, b1, rotate); RB(a2, b2, rotate); RB(a3, b3, rotate);
			RB1(x, y, a1, b1); RB1(x, y, a2, b2); RB1(x, y, a3, b3);
							   
		}
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

	Block block;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "#          #" << endl;
	cout << "############" << endl;

    return 0;
}

