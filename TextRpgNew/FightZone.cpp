#include "FightZone.h"
#include <conio.h>
#include <iostream>

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First); // _First가 _Second 때림
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

void FightZone::Fight(FightUnit& _Player)
{
	NewMonster.SetName("Monster");
	//NewMonster.AddSpeed(5); // 테스트용
	while (true)
	{
		_Player.StatusRender();
		NewMonster.StatusRender();

		// 선공 후공이 결정 나고
		// 조건에 따라서

		bool IsEnd = false;

		// 속도가 빠르고 체력이 적으면 선공
		int PlayerStat = _Player.GetSpeed() - _Player.GetHp();
		int MonsterStat = NewMonster.GetSpeed() - NewMonster.GetHp();

		if (PlayerStat > MonsterStat) {
			// Player 선공
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else {
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

		if (true == IsEnd) {	// 죽었으면 끝
				return;
		}
		else {					// 안 끝났으면 한 쪽에 속도 지급
			// Player의 이전 공격력이 더 쎘으면 Player 속도 [1]만큼 추가
			int gap = _Player.GetCurDamage() - NewMonster.GetCurDamage();
			if (gap > 0) {
				_Player.AddSpeed(1);
			}
			else if (gap < 0) {
				NewMonster.AddSpeed(1);
			}
		}
	}

}