#pragma once
#include "ConsoleObject.h"
class Bullet : public ConsoleObject
{
public:
	Bullet();
	Bullet(const int2& _StartPos, char _RenderChar);

	bool& GetIsFireRef();

private:
	//int2 Pos = { 0, 0 };
	//char RenderChar = '@';
	bool IsFire = false;
};
