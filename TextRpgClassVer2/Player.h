// 헤더에는 아래의 #pragma once를 꼭 넣어야 합니다.
#pragma once
#include "ConsoleObject.h"

// 헤더에는 선언만 놓습니다.
class Player : public ConsoleObject
{
public:
	Player();
	Player(const int2& _StartPos, char _RenderChar);

	void Update();
	void SetBulletFire(bool* _IsFire);

private:
	//int2 Pos = { 0, 0 };
	//char RenderChar = '@';
	bool* IsFire = nullptr;
};
