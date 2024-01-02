#include "FightZone.h"
#include <conio.h>
#include <iostream>
#include "Player.h"

FightZone::FightZone()
{
	NewMonster.SetName("Monster");
}

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		printf_s("게임 종료\n");
		return true;
	}


	{
		int Input = _getch();
	}

	system("cls");
	_First.DamageLogic(_Second);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	_Second.DamageRender();
	if (true == _First.IsDeath())
	{
		printf_s("게임 종료\n");
		return true;
	}
	{
		int Input = _getch();
	}
	system("cls");

	return false;
}

void FightZone::In(Player& _Player)
{
	//초급 중급 고급 사냥터 고르기
	_Player.StatusRender();
	printf_s("어디로 가시겠습니다.\n");
	printf_s("1. 초급 사냥터.\n");
	printf_s("2. 중급 사냥터.\n");
	printf_s("3. 고급 사냥터.\n");
	printf_s("4. 나간다.\n");
	int Select = _getch();

	system("cls");

	switch (Select)
	{
	case '1':
	{
		// 초급
		NewMonster.SetMinAtt(5);
		NewMonster.SetMaxAtt(15);
		NewMonster.SetMaxHp(100);
		NewMonster.Heal();
		NewMonster.AddGold(8000);
		break;
	}
	case '2':
	{
		// 중급
		NewMonster.SetMinAtt(10);
		NewMonster.SetMaxAtt(20);
		NewMonster.SetMaxHp(200);
		NewMonster.Heal();
		NewMonster.AddGold(11000);
		break; 
	}
	case '3':
	{
		// 고급
		NewMonster.SetMinAtt(20);
		NewMonster.SetMaxAtt(40);
		NewMonster.SetMaxHp(300);
		NewMonster.Heal();
		NewMonster.AddGold(13000);
		break;
	}
	case '4':
		return;
	default:
		break;
	}

	system("cls");

	while (true)
	{
		_Player.StatusRender();
		NewMonster.StatusRender();

		// 선공 후공이 결정 나고
		// 조건에 따라서

		bool IsEnd = false;

		if (_Player.GetRandomSpeed() >= NewMonster.GetRandomSpeed())
		{
			printf_s("플레이어의 선공\n");

			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else 
		{
			printf_s("몬스터의 선공\n");
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

			if (true == IsEnd) // 누군가 죽어서 싸움이 끝남.
			{
				NewMonster.Heal();
				if (!_Player.IsDeath()) { // Player가 이긴거라면 골드를 지급.
					int MonsterGold = NewMonster.GetGold();
					printf("%s가 %d의 골드를 얻었습니다.\n", _Player.GetName(), MonsterGold);
					_Player.AddGold(MonsterGold);
					_getch();
				}
				return;
			}
	}

}