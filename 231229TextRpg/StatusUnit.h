#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	void StatusRender();
	int GetGold();
	inline int GetExp() const {
		return Exp;
	}
	void AddGold(int _Gold);
	void SubGold(int _Gold);
	int RandomValue(int _Min, int _Max);
	virtual void StatusRenderStart();
	virtual void StatusRenderBase();
	virtual void StatusRenderEnd();
	void SetExp(int _Exp);
protected:
	int Hp = 100;
	int MaxHp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 20; // 0~20
	int Gold = 100000;
	int Exp = 0;
};

