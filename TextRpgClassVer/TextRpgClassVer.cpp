#include <iostream>
#include <conio.h>

class Player
{
public:
	Player()
	{
	}
	void StatusRender()
	{
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

	bool IsDeath() {
		/*if (Hp <= 0) {
			return true;
		}
		else {
			return false;
		}*/
		return Hp <= 0;
	}

private:
	char Name[100] = "Fighter";
	int Hp = 100;
	int Att = 10;
};

class Monster
{
public:
	Monster()
	{
	}

	void StatusRender()
	{
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

	bool IsDeath() {
		return Hp <= 0;
	}

private:
	char Name[100] = "Orc";
	int Hp = 50;
	int Att = 5;
};


int main()
{
	Player NewPlayer = Player();
	Monster NewMonster = Monster();

	while (true)
	{
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		{
			int Input = _getch();
		}

		system("cls");
		NewMonster.DamageLogic(NewPlayer.GetAtt());
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewPlayer.DamageRender();
		if (NewMonster.IsDeath())
		{
			printf_s("게임 종료\n");
			break;
		}

		{
			int Input = _getch();
		}

		system("cls");
		NewPlayer.DamageLogic(NewMonster.GetAtt());
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewPlayer.DamageRender();
		NewMonster.DamageRender();

		{
			int Input = _getch();
		}

		// 누군가 죽었다면 게임이 끝나야죠?
		// Player와 몬스터에 bool을 리턴하는 IsDeath()를 만들어서
		// 누구든 Hp가 0이하가 되면 true를 리턴해서
		// 종료가 되게 하세요.
		if (NewPlayer.IsDeath())
		{
			printf_s("게임 종료\n");
			break;
		}

		// 콘솔창에 명령을 요청한다.
		system("cls");
	}
}

