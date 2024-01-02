#include "Player.h"
#include <iostream>

Player::Player()
{
	// ���� �׽�Ʈ �ڵ�
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

int Player::GetTotalExp() {
	return TotalExp;
}
int Player::GetLevelUpExp() {
	return LevelUpExp;
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt();
	return CurDamage;
}

void Player::SetLevel(int _level) {
	Level = _level;
}
void Player::SetTotalExp(int _exp) {
	TotalExp += _exp;
}
void Player::SetLevelUpExp(int _exp) {
	LevelUpExp += _exp;
}

void Player::FightEnd(FightUnit& _Other) {
	int Gold = _Other.GetGold();
	printf("%s�� %d�� ��带 ������ϴ�.\n", GetName(), Gold);
	AddGold(Gold);

	// ����ġ ���, ����ġ ���� ������
	printf("%s�� %d�� ����ġ�� ������ϴ�.\n", GetName(), GameExp);
	TotalExp += GameExp;
	if (TotalExp >= LevelUpExp) {
		Level += TotalExp / LevelUpExp;
		TotalExp -= (TotalExp / LevelUpExp) * LevelUpExp;
		// LevelUpExp�� ��� �״��??
		printf("%s�� %d.Lv�� ������ �߽��ϴ�.\n", GetName(), Level);
		SetMinAtt(GetMinAtt() + 10);
		SetMaxAtt(GetMaxAtt() + 10);
		SetMaxHp(GetMaxHP() + 50);
		LevelUpExp += 1000;
	}
}
void Player::StatusRenderStart() {
	printf_s("���� %d\n", Level);
	printf_s("����ġ %d/%d\n", TotalExp, LevelUpExp);
}