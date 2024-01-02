// ������� �Ʒ��� #pragma once�� �� �־�� �մϴ�.
#pragma once
#include "ConsoleObject.h"

// ������� ���� �����ϴ�.
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
