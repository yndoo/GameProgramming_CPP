// 헤더에는 #pragma once를 꼭 넣어어ㅑ 함.
#pragma once
#include<iostream>

extern int Value;
// 헤더에는 선언만 놓기.
class Player
{
public:
	Player()
	{
	}

	void StatusRender()
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

	bool IsDeath()
	{
		return Hp <= 0;
	}

	void DamageLogic(int _Att)
	{
		Hp -= _Att;
	}

	int GetAtt()
	{
		return Att;
	}

	void DamageRender()
	{
		printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", Name, Att);
	}

protected:

private:
	char Name[100] = "Fighter";
	int Hp = 100;
	int Att = 10;
};