#pragma once
#include "EngineDebug.h"
class ConsoleScreen
{
public:

	void CreateScreen(int _ScreenX, int _ScreenY);
	void ReleaseScreen();
	void PrintScreen();
protected:

private:
	int ScreenX = -1;	// ���� ȭ���� ��������� ���� ���� ǥ���ϱ� ���� ����
	int ScreenY = -1;
	char** ScreenData = nullptr;	// ���� ���ϴ� ���� ������ �� �� �ִ�
};

