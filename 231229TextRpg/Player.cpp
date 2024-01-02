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
	int MonsterGold = _Other.GetGold();
	printf("%s�� %d�� ��带 ������ϴ�.\n", GetName(), MonsterGold);
	AddGold(MonsterGold);

	// ����ġ ���, ����ġ ���� ������
	printf("%s�� %d�� ����ġ�� ������ϴ�.\n", GetName(), Exp);
	TotalExp += Exp;

	while (TotalExp >= LevelUpExp) {
		Level ++;
		TotalExp -= LevelUpExp;
		SetMinAtt(GetMinAtt() + 10);
		SetMaxAtt(GetMaxAtt() + 10);
		SetMaxHp(GetMaxHP() + 50);
		LevelUpExp = Level * 1000;
		HpReset();
		printf("%s�� %d.Lv�� ������ �߽��ϴ�.\n", GetName(), Level);
	}
}
void Player::StatusRenderStart() {
	printf_s("���� %d\n", Level);
	printf_s("����ġ %d/%d\n", TotalExp, LevelUpExp);
}