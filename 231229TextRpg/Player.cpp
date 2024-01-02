#include "Player.h"
#include <iostream>

Player::Player()
{
	// 지금 테스트 코드
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
	printf("%s가 %d의 골드를 얻었습니다.\n", GetName(), MonsterGold);
	AddGold(MonsterGold);

	// 경험치 얻기, 경험치 차면 레벨업
	printf("%s가 %d의 경험치를 얻었습니다.\n", GetName(), Exp);
	TotalExp += Exp;

	while (TotalExp >= LevelUpExp) {
		Level ++;
		TotalExp -= LevelUpExp;
		SetMinAtt(GetMinAtt() + 10);
		SetMaxAtt(GetMaxAtt() + 10);
		SetMaxHp(GetMaxHP() + 50);
		LevelUpExp = Level * 1000;
		HpReset();
		printf("%s가 %d.Lv로 레벨업 했습니다.\n", GetName(), Level);
	}
}
void Player::StatusRenderStart() {
	printf_s("레벨 %d\n", Level);
	printf_s("경험치 %d/%d\n", TotalExp, LevelUpExp);
}