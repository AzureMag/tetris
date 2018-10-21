// test.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

using namespace std;

int main() {
	cout << "키보드의 상하좌우를 입력하세요." << endl;

	int keys = 0;
	do {
		keys = _getch();
		switch (keys) {
		case LEFT:
			cout << " left" << endl;
			break;
		case RIGHT:
			cout << " right" << endl;
			break;
		case UP:
			cout << " up" << endl;
			break;
		case DOWN:
			cout << " down" << endl;
			break;
		}
	} while (keys != ESC);

	system("pause");
	return 0;
}

