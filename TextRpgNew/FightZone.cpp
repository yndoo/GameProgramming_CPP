#include "FightZone.h"
#include <conio.h>
#include <iostream>

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First); // _First�� _Second ����
	_Top.StatusRender();
	_Bot.StatusRender();

	_First.DamageRender(); 
	if (true == _Second.IsDeath())
	{
		printf_s("���� ����\n");
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
		printf_s("���� ����\n");
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
	//NewMonster.AddSpeed(5); // �׽�Ʈ��
	while (true)
	{
		_Player.StatusRender();
		NewMonster.StatusRender();

		// ���� �İ��� ���� ����
		// ���ǿ� ����

		bool IsEnd = false;

		// �ӵ��� ������ ü���� ������ ����
		int PlayerStat = _Player.GetSpeed() - _Player.GetHp();
		int MonsterStat = NewMonster.GetSpeed() - NewMonster.GetHp();

		if (PlayerStat > MonsterStat) {
			// Player ����
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else {
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

		if (true == IsEnd) {	// �׾����� ��
				return;
		}
		else {					// �� �������� �� �ʿ� �ӵ� ����
			// Player�� ���� ���ݷ��� �� ������ Player �ӵ� [1]��ŭ �߰�
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