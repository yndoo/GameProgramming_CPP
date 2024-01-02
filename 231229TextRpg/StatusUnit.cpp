#include "StatusUnit.h"
#include <iostream>

void StatusUnit::StatusRenderStart() {

}

void StatusUnit::StatusRenderBase() {
	printf_s("���ݷ� %d~%d\n", MinAtt, MaxAtt);
	printf_s("ü�� %d/%d\n", Hp, MaxHp);
	printf_s("������ %d\n", Gold);
}

void StatusUnit::StatusRenderEnd() {

}

void StatusUnit::StatusRender()
{
	// �޸𸮿� ���õ� ��Ȯ�� ������ ���� ��������
	// �ڽ��� �ɹ��Լ����� �ڽ��� �ɹ������� �����Ӱ� ����� �����մϴ�.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}


	printf_s("\n");
	StatusRenderStart();
	StatusRenderBase();
	StatusRenderEnd();
	//printf_s("���ݷ� %d~%d\n", MinAtt, MaxAtt);
	//printf_s("ü�� %d/%d\n", Hp, MaxHp);
	//printf_s("������ %d\n", Gold);

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