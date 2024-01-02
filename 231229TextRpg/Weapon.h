#pragma once
#include "NameUnit.h"

class Weapon : public NameUnit
{
public:
	inline int GetAtt() const
	{
		return Att;
	}

	inline void SetAtt(int _Att) 
	{
		Att = _Att;
	}
	inline int GetEquipUp() const { // ����Լ��� const : �� �Լ� �������� �ƹ��͵� �ٲ� �� ������ �ǹ�.
		return EquipUp;
	}
	inline int GetEquipCost() const {
		return EquipCost;
	}
	void SetEquipCost();
	void SuccessEquipUp(int up);
	void FailEquipUp(int resetLv);
	void EquipRender();
	void EquipLevelUp();

private:
	int EquipUp = 1; // ��ȭ ����(��ȭ ��ġ)
	int EquipCost = 1;
	int Att;
};

