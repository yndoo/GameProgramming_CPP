#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{
}

int FightUnit::GetRandomAtt() 
{
	// Hp = 500;
	// 39212312 0~10
	int Damage = rand() % ((MaxAtt - MinAtt) + 1);
	CurDamage = MinAtt + Damage;
	return MinAtt + Damage;
}

int FightUnit::GetRandomSpeed() const
{
	return rand() % (Speed + 1);
}

int FightUnit::GetHp() const {
	return Hp;
}
void FightUnit::HpReset() {
	Hp = MaxHp;
}

void FightUnit::DamageLogic(FightUnit& _Unit)
{
	Hp -= _Unit.GetRandomAtt();

	if (0 > Hp)
	{
		Hp = 0;
	}
}

void FightUnit::DamageRender()
{
	printf_s("%s �� %d�� ���ݷ����� �����߽��ϴ�.\n", Name, CurDamage);
}


void FightUnit::SetMinAtt(int _NewAtt) {
	MinAtt = _NewAtt;
}

void FightUnit::SetMaxAtt(int _NewAtt) {
	MaxAtt = _NewAtt;
}
void FightUnit::SetMaxHp(int _NewHp) {
	MaxHp = _NewHp;
}