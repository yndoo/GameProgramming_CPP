#include "Player.h"
Player:: Player()
{
}

void Player::StatusRender()
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

bool Player::IsDeath()
{
	return Hp <= 0;
}

void Player::DamageLogic(int _Att)
{
	Hp -= _Att;
}

int Player::GetAtt()
{
	return Att;
}

void Player::DamageRender()
{
	printf_s("%s �� %d�� ���ݷ����� �����߽��ϴ�.\n", Name, Att);
}
