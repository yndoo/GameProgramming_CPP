#include "Monster.h"
#include <iostream>

void Monster::FightStart(FightUnit& _Other) {
	Heal();
	AddGold(10000);
}

void Monster::FightEnd(FightUnit& _Other) {
	// ���Ͱ� �ο� ���� �� �ؾ� �� ��

	// �����ϰ� ����ġ�� ���ؾ� �Ѵ�.
	// 1000 ~ 2000 ������ ����ġ ���
	int rExp = rand() % 1000 + 1000; // 1000 ~ 1999
	_Other.SetExp(rExp); 
	
}