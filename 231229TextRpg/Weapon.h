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
	inline int GetEquipUp() const { // 멤버함수에 const : 이 함수 내에서는 아무것도 바꿀 수 없음을 의미.
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
	int EquipUp = 1; // 강화 레벨(강화 수치)
	int EquipCost = 1;
	int Att;
};

