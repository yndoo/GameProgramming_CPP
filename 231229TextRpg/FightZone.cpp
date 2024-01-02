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

void FightZone::In(Player& _Player)
{
	//�ʱ� �߱� ��� ����� ����
	_Player.StatusRender();
	printf_s("���� ���ðڽ��ϴ�.\n");
	printf_s("1. �ʱ� �����.\n");
	printf_s("2. �߱� �����.\n");
	printf_s("3. ��� �����.\n");
	printf_s("4. ������.\n");
	int Select = _getch();

	system("cls");

	switch (Select)
	{
	case '1':
	{
		// �ʱ�
		NewMonster.SetMinAtt(5);
		NewMonster.SetMaxAtt(15);
		NewMonster.SetMaxHp(100);
		NewMonster.Heal();
		NewMonster.AddGold(8000);
		break;
	}
	case '2':
	{
		// �߱�
		NewMonster.SetMinAtt(10);
		NewMonster.SetMaxAtt(20);
		NewMonster.SetMaxHp(200);
		NewMonster.Heal();
		NewMonster.AddGold(11000);
		break; 
	}
	case '3':
	{
		// ���
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

		// ���� �İ��� ���� ����
		// ���ǿ� ����

		bool IsEnd = false;

		if (_Player.GetRandomSpeed() >= NewMonster.GetRandomSpeed())
		{
			printf_s("�÷��̾��� ����\n");

			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else 
		{
			printf_s("������ ����\n");
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

			if (true == IsEnd) // ������ �׾ �ο��� ����.
			{
				NewMonster.Heal();
				if (!_Player.IsDeath()) { // Player�� �̱�Ŷ�� ��带 ����.
					int MonsterGold = NewMonster.GetGold();
					printf("%s�� %d�� ��带 ������ϴ�.\n", _Player.GetName(), MonsterGold);
					_Player.AddGold(MonsterGold);
					_getch();
				}
				return;
			}
	}

}