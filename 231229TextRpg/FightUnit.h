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
	inline int GetMaxAtt() const
	{
		return MaxAtt;
	}

	virtual int GetRandomAtt();

	int GetRandomSpeed() const;
	int GetHp() const;

	void Heal();

	// Fight¿ë ÇÔ¼ö
	void DamageLogic(FightUnit& _Unit);
	void DamageRender();

	// Set
	void SetMinAtt(int _NewAtt);
	void SetMaxAtt(int _NewAtt);
	void SetMaxHp(int _NewHp);
protected:
	int CurDamage = 0;

private:
};
