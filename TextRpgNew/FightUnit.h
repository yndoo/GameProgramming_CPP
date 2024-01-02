#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();
	// Get
	inline bool IsDeath() const
	{
		return Hp <= 0;
	}

	inline int GetMinAtt() const
	{
		return MinAtt;
	}
	inline int GetCurDamage() {
		return CurDamage;
	}
	// Fight�� �Լ�
	void DamageLogic(FightUnit& _Unit);

	void DamageRender();

protected:

private:
	int rDamage = 0; // ���� ������ ���
	int CurDamage = 0;
};
