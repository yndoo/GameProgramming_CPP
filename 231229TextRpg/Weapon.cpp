#include "Weapon.h"
#include <iostream>
#include <conio.h>
void Weapon::SetEquipCost() {
	EquipCost = EquipUp * 10;
}

void Weapon::SuccessEquipUp(int up) {
	EquipUp += up;
	printf_s("��ȭ�� �����߽��ϴ�.\n");
	_getch();
}
void Weapon::FailEquipUp(int down) {
	EquipUp -= down;
	printf_s("��ȭ�� �����߽��ϴ�.\n");
	_getch();
}

void Weapon::EquipRender() {

	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("���� ���� %d\n", EquipUp);

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
	else if (EquipUp >= 10 && EquipUp < 20) { // ���� ������ 10�̻� 20�̸��� ��
		//int result = rand() % 10; 
		int result = 1;
		if (result != 0) { 
			// ��ȭ ����
			SuccessEquipUp(1);
		}
		else {
			// ��ȭ ����
			FailEquipUp(5);
		}
	}
	else if (EquipUp >= 20 && EquipUp < 30) {
		//int result = rand() % 5; 
		int result = 1;
		if (result != 0) {
			// ��ȭ ����
			SuccessEquipUp(1);
		}
		else {
			// ��ȭ ����
			FailEquipUp(EquipUp);
		}
	}
	SetEquipCost();
}
