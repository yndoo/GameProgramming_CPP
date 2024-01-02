#include "Player.h"
Player:: Player()
{
}

void Player::StatusRender()
{
	// 메모리에 관련된 명확한 설명은 안한 상태지만
	// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("공격력 %d\n", Att);
	printf_s("체력 %d\n", Hp);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}

bool Player::IsDeath()
{
	return Hp <= 0;
}

void Player::DamageLogic(int _Att)
{
	Hp -= _Att;
}

int Player::GetAtt()
{
	return Att;
}

void Player::DamageRender()
{
	printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", Name, Att);
}
