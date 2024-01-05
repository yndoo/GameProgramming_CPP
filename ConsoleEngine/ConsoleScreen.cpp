#include "ConsoleScreen.h"
#include <iostream>
#include <Windows.h>
#include <assert.h>
#include<conio.h>

void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY) {
	ReleaseScreen();

	if (_ScreenX <= 0) {
		MsgBoxAssert("��ũ�� Xũ�Ⱑ 0�̱� ������ �ܼ� ��ũ���� ���� �� �����ϴ�.");
	}
	if (_ScreenY <= 0) {
		MsgBoxAssert("��ũ�� Yũ�Ⱑ 0�̱� ������ �ܼ� ��ũ���� ���� �� �����ϴ�.");
	}
	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	if (nullptr != ScreenData) {
		MsgBoxAssert("�̹� ��ũ�������Ͱ� �ֽ��ϴ�");
	}

	ScreenData = new char* [ScreenY];
	if (nullptr == ScreenData) {
		MsgBoxAssert("��ũ�� ������ �����߽��ϴ�. if (nullptr == ScreenData)")
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
	// ���� ���� ������ �������� ������ ��
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