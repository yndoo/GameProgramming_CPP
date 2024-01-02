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
	inline int GetMaxHP() const {
		return MaxHp;
	}

	virtual int GetRandomAtt();

	int GetRandomSpeed() const;
	int GetHp() const;

	void Heal();

	// Fight용 함수
	void DamageLogic(FightUnit& _Unit);
	void DamageRender();
	virtual void FightEnd(FightUnit& _Other) {}
	virtual void FightStart(FightUnit& _Other) {}

	// Set
	void SetMinAtt(int _NewAtt);
	void SetMaxAtt(int _NewAtt);
	void SetMaxHp(int _NewHp);
	void SetExp(int _exp);
protected:
	int CurDamage = 0;
	int GameExp = 0; // 싸움에서 주거나 받는 경험치
private:
};
