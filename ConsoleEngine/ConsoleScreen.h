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
	int ScreenX = -1;	// 아직 화면이 만들어지지 않은 것을 표현하기 위해 음수
	int ScreenY = -1;
	char** ScreenData = nullptr;	// 내가 원하는 순간 생성을 할 수 있다
};

