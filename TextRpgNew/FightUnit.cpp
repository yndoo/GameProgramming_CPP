#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{
}

void FightUnit::DamageLogic(FightUnit& _Unit) // _Unit�� ������ ��
{
	rDamage = rand() % (_Unit.MaxAtt - _Unit.MinAtt + 1) + _Unit.MinAtt; // Min ~ Max ������ ������ ���ݷ����� ����.
	_Unit.CurDamage= rDamage;

	Hp -= rDamage;
	if (Hp < 0) {
		Hp = 0;
	}
}

void FightUnit::DamageRender()
{
	printf_s("%s �� %d ~ %d ������ ���ݷ�(%d)���� �����߽��ϴ�.\n", Name, MinAtt, MaxAtt, CurDamage);
}