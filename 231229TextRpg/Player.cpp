#include "Player.h"

Player::Player()
{
	// ���� �׽�Ʈ �ڵ�
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt();
	return CurDamage;
}