// ������� #pragma once�� �� �־��� ��.
#pragma once
#include<iostream>

extern int Value;
// ������� ���� ����.
class Player
{
public:
	Player()
	{
	}

	void StatusRender()
	{
		// �޸𸮿� ���õ� ��Ȯ�� ������ ���� ��������
		// �ڽ��� �ɹ��Լ����� �ڽ��� �ɹ������� �����Ӱ� ����� �����մϴ�.
		int Size = printf_s("%s ", Name);
		for (int i = 0; i < 50 - Size; i++)
		{
			printf_s("-");
		}

		printf_s("\n");
		printf_s("���ݷ� %d\n", Att);
		printf_s("ü�� %d\n", Hp);

		for (int i = 0; i < 50; i++)
		{
			printf_s("-");
		}

		printf_s("\n");
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}

	void DamageLogic(int _Att)
	{
		Hp -= _Att;
	}

	int GetAtt()
	{
		return Att;
	}

	void DamageRender()
	{
		printf_s("%s �� %d�� ���ݷ����� �����߽��ϴ�.\n", Name, Att);
	}

protected:

private:
	char Name[100] = "Fighter";
	int Hp = 100;
	int Att = 10;
};