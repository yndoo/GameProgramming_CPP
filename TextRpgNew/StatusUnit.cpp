#include "StatusUnit.h"
#include <iostream>

void StatusUnit::SetName(const char* _Name)
{
	int Count = 0;
	while (*(_Name + Count)) {
		Count++;
	}
	
	for (int i = 0; i < Count; i++) {
		Name[i] = _Name[i];
	}
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
	printf_s("���ݷ� %d~%d\n", MinAtt, MaxAtt);
	printf_s("�ӵ� %d\n", Speed);
	printf_s("ü�� %d\n", Hp);
	//printf_s("ü�� - �ӵ� %d\n", Hp - Speed);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}
int StatusUnit::GetHp() {
	return Hp;
}
int StatusUnit::GetSpeed() {
	return Speed;
}
void StatusUnit::AddSpeed(int _point) {
	Speed += _point;
	//printf_s("%s ���� %d Speed �߰�\n", Name, _point);
}