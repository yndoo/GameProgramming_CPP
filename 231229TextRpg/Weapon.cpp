#include "Weapon.h"
#include <iostream>
#include <conio.h>
void Weapon::SetEquipCost() {
	EquipCost = EquipUp * 10;
}

void Weapon::SuccessEquipUp(int up) {
	EquipUp += up;
	printf_s("강화에 성공했습니다.\n");
	_getch();
}
void Weapon::FailEquipUp(int down) {
	EquipUp -= down;
	printf_s("강화에 실패했습니다.\n");
	_getch();
}

void Weapon::EquipRender() {

	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("무기 레벨 %d\n", EquipUp);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}

void Weapon::EquipLevelUp() {
	if (EquipUp < 10) {
		SuccessEquipUp(1);
	}
	else if (EquipUp >= 10 && EquipUp < 20) { // 무기 레벨이 10이상 20미만일 때
		//int result = rand() % 10; 
		int result = 1;
		if (result != 0) { 
			// 강화 성공
			SuccessEquipUp(1);
		}
		else {
			// 강화 실패
			FailEquipUp(5);
		}
	}
	else if (EquipUp >= 20 && EquipUp < 30) {
		//int result = rand() % 5; 
		int result = 1;
		if (result != 0) {
			// 강화 성공
			SuccessEquipUp(1);
		}
		else {
			// 강화 실패
			FailEquipUp(EquipUp);
		}
	}
	SetEquipCost();
}
