#include "ConsoleScreen.h"
#include <iostream>
#include <Windows.h>
#include <assert.h>
#include<conio.h>

void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY) {
	ReleaseScreen();

	if (_ScreenX <= 0) {
		MsgBoxAssert("스크린 X크기가 0이기 때문에 콘솔 스크린을 만들 수 없습니다.");
	}
	if (_ScreenY <= 0) {
		MsgBoxAssert("스크린 Y크기가 0이기 때문에 콘솔 스크린을 만들 수 없습니다.");
	}
	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	if (nullptr != ScreenData) {
		MsgBoxAssert("이미 스크린데이터가 있습니다");
	}

	ScreenData = new char* [ScreenY];
	if (nullptr == ScreenData) {
		MsgBoxAssert("스크린 생성에 실패했습니다. if (nullptr == ScreenData)")
	}

	for (int y = 0; y < ScreenY; y++) {
		ScreenData[y] = new char[ScreenX + 2] {0, };
		for (int x = 0; x < ScreenX; x++) {
			ScreenData[y][x] = '*';
		}
		ScreenData[y][ScreenX] = '\n';
	}

}

void ConsoleScreen::ReleaseScreen() {
	// 지울 때는 무조건 역순으로 지워야 함
	for (int y = 0; y < ScreenY; y++){
		if (ScreenData[y] == nullptr) {
			continue;
		}
		delete[] ScreenData[y];
		ScreenData[y] = nullptr;
	}
	if (nullptr != ScreenData) {
		delete[] ScreenData;
		ScreenData = nullptr;
	}
}

void ConsoleScreen::PrintScreen() {
	system("cls");

	for (int y = 0; y < ScreenY; y++) {
		printf_s(ScreenData[y]);
	}

	_getch();
}