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
	// 메모리에 관련된 명확한 설명은 안한 상태지만
	// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("공격력 %d~%d\n", MinAtt, MaxAtt);
	printf_s("속도 %d\n", Speed);
	printf_s("체력 %d\n", Hp);
	//printf_s("체력 - 속도 %d\n", Hp - Speed);

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
	//printf_s("%s 에게 %d Speed 추가\n", Name, _point);
}