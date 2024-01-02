#include "StatusUnit.h"
#include <iostream>

void StatusUnit::StatusRenderStart() {

}

void StatusUnit::StatusRenderBase() {
	printf_s("공격력 %d~%d\n", MinAtt, MaxAtt);
	printf_s("체력 %d/%d\n", Hp, MaxHp);
	printf_s("소지금 %d\n", Gold);
}

void StatusUnit::StatusRenderEnd() {

}

void StatusUnit::StatusRender()
{
	// 메모리에 관련된 명확한 설명은 안한 상태지만
	// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}


	printf_s("\n");
	StatusRenderStart();
	StatusRenderBase();
	StatusRenderEnd();
	//printf_s("공격력 %d~%d\n", MinAtt, MaxAtt);
	//printf_s("체력 %d/%d\n", Hp, MaxHp);
	//printf_s("소지금 %d\n", Gold);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}
int StatusUnit::GetGold() {
	return Gold;
}
void StatusUnit::AddGold(int _Gold) {
	Gold += _Gold;
}
void StatusUnit::SubGold(int _Gold) {
	if (Gold - _Gold >= 0) {
		Gold -= _Gold;
	}
}

int StatusUnit::RandomValue(int _Min, int _Max) {
	int RandomValue = rand() % (_Max - _Min) + _Min;
	return RandomValue;
}

void StatusUnit::SetExp(int _Exp) {
	Exp = _Exp;
}