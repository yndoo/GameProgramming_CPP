#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

	// �̷� ��쿡 public���� �Ѵ�.
	// ������ ��� �ִ� ��쿡��.
	// ���� �̷���.
	// �����ͷ� �ؾ� �մϴ�.

	// ���� ������� �������� ����
	// �̰� ������ �ؾ�����
	// �����ͷ� �ؾ�����.

	// ���� �����ϰų� �������� ���� ���ɼ��� �ִٸ� => ������
	// ����� ������� �ʾƾ� �ϸ� => ����
	// ������ �����Ҵ��� ����� �ʾұ� ������ 
	Weapon Weapon;
	
	int GetTotalExp();
	int GetLevelUpExp();

	void SetLevel(int _level);
	void SetTotalExp(int _exp);
	void SetLevelUpExp(int _exp);

	//void FightStart(FightUnit& _Other) override;
	void FightEnd(FightUnit& _Other) override;
	void StatusRenderStart() override;
protected:
	int GetRandomAtt() override;
private:
	int Level = 1;
	int TotalExp = 0;
	int LevelUpExp = 1000; // ���⿡ �����ϸ� �������Ѵ�.
};

