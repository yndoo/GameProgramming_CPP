#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('|');
}

void Bullet::Update()
{
	if (0 > GetPos().Y)
	{
		// ���� �����Ǵ� �����ȿ��� �������� �ϱ� ������.
		// ������ �̷��� �������̽��� �츮���� ������� �մϴ�.
		// delete this; <= ���� ����� �ȵȴ�.
		Destroy();
		return;
	}

	AddPos(Up);
}