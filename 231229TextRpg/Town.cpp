#include "Town.h"
#include <iostream>
#include <conio.h>
#include "Player.h"

void Town::WeaponUp(Player& _Player)
{
    // �����е��� �ǵ���� �ϴ� �κ��� ���� ���Դϴ�.

    // 1. �÷��̾��� ������ ��ȭ ���¸� �����ش�.
    // ���� �׷����� �������� ���δ� �����.
    // 1���������� ��ȭ
    // 2���������� ������.
    // 30���� ������ ����� ��ȭ�� �� �ȴٰ� �����.

    system("cls");

    while (true) {
        _Player.StatusRender();
        //���� ��ȭ ���� �����ֱ�
        _Player.Weapon.EquipRender();


        if (_Player.Weapon.GetEquipUp() >= 30) {
            printf_s("���Ⱑ �ִ� �����Դϴ�.\n");
            printf_s("1. ������.\n");

            int Select = _getch();
            switch (Select)
            {
            case '1':
                return;
            default:
                break;
            }

            system("cls");
        }

        printf_s("���⸦ ��ȭ �Ͻðڽ��ϱ�.\n");
        printf_s("1. ��ȭ.\n");
        printf_s("2. ������.\n");
        int Select = _getch();

        switch (Select)
        {
        case '1':
            if (_Player.GetGold() >= _Player.Weapon.GetEquipCost()) {
                _Player.SubGold(_Player.Weapon.GetEquipCost());
                _Player.Weapon.EquipLevelUp();
            }
            else {
                system("cls");
                _Player.StatusRender();
                printf_s("��尡 �����մϴ�.\n");
                printf_s("1. ������.\n");

                int Select = _getch();
                switch (Select)
                {
                case '1':
                    return;
                default:
                    break;
                }

                system("cls");
            }
            break;
        case '2':
            return;
        default:
            break;
        }

        system("cls");

    }

    // 2.��
    // 1������ 10�������� �����ص� ��ȭ��ġ�� �������� �ʽ��ϴ�.
    // 10������ 20�������� �����ϸ� ��ȭ��ġ�� 5�� �������ϴ�.
    // 20������ 30�������� �����ϸ� ��ȭ��ġ�� 0�� �˴ϴ�.
    // ��ȭȮ�� �������
}

void Town::Heal(Player& _Player)
{
    system("cls");

    while (true) {
        _Player.HpReset();
        _Player.StatusRender();
        printf_s("%s�� ġ��Ǿ����ϴ�.\n", _Player.GetName());

        printf_s("1. ������.\n");
        int Select = _getch();

        switch (Select)
        {
        case '1':
            return;
        default:
            break;
        }

        system("cls");

    }

}

void Town::In(Player& _Player)
{
    while (true)
    {
        _Player.StatusRender();
        printf_s("�������� ������ �Ͻðڽ��ϱ�.\n");
        printf_s("1. ��ȭ.\n");
        printf_s("2. ġ��.\n");
        printf_s("3. ������.\n");
        int Select = _getch();

        switch (Select)
        {
        case '1':
            WeaponUp(_Player);
            break;
        case '2':
            Heal(_Player);
            break;
        case '3':
            return;
        default:
            break;
        }

        system("cls");
    }

}
