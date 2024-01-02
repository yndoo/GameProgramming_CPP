#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{
}

void FightUnit::DamageLogic(FightUnit& _Unit) // _Unit이 때리는 것
{
	rDamage = rand() % (_Unit.MaxAtt - _Unit.MinAtt + 1) + _Unit.MinAtt; // Min ~ Max 사이의 랜덤한 공격력으로 공격.
	_Unit.CurDamage= rDamage;

	Hp -= rDamage;
	if (Hp < 0) {
		Hp = 0;
	}
}

void FightUnit::DamageRender()
{
	printf_s("%s 가 %d ~ %d 사이의 공격력(%d)으로 공격했습니다.\n", Name, MinAtt, MaxAtt, CurDamage);
}