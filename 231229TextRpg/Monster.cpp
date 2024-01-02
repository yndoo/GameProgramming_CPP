#include "Monster.h"
#include <iostream>

void Monster::FightStart(FightUnit& _Other) {
	Heal();
	AddGold(10000);
}

void Monster::FightEnd(FightUnit& _Other) {
	// 몬스터가 싸움 끝난 후 해야 할 일

	// 랜덤하게 경험치를 정해야 한다.
	// 1000 ~ 2000 사이의 경험치 계산
	int rExp = rand() % 1000 + 1000; // 1000 ~ 1999
	_Other.SetExp(rExp); 
	
}