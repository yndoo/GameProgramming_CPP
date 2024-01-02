#pragma once
#include "Monster.h"

class FightZone
{
public:
	// ����� ���ö������� ����
	void Fight(FightUnit& _Player);

private:
	Monster NewMonster = Monster();

	// �ѹ��� ����
	// ����� ������ ������ �����ؾ� �մϴ�.
	bool FightLogic(FightUnit& _Left, FightUnit& _Right, FightUnit& _Top, FightUnit& _Bot);
};

