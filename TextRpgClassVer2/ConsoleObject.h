#pragma once
#include "Math.h"

// 자식들이 공통적으로 가져야 할 기능을 만들어야 한다.
class ConsoleObject
{
public:
	ConsoleObject();
	ConsoleObject(const int2& _StartPos, char _RenderChar);
	int2 GetPos();
	void SetPos(const int2& _Pos);
	char GetRenderChar();
protected:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};

 