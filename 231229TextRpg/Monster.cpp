#include "Monster.h"
#include <iostream>

void Monster::FightStart(FightUnit& _Other) {
	HpReset();
	AddGold(RandomValue(5000,10000)); //�������
}

void Monster::FightEnd(FightUnit& _Other) {
	// ���Ͱ� �ο� ���� �� �ؾ� �� ��

	// �����ϰ� ����ġ�� ���ؾ� �Ѵ�.
	// 1000 ~ 2000 ������ ����ġ ���
	_Other.SetExp(RandomValue(1000, 2000));
}

void Monster::StatusRenderEnd() {

}