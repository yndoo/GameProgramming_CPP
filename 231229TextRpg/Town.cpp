#include "Town.h"
#include <iostream>
#include <conio.h>
#include "Player.h"

void Town::WeaponUp(Player& _Player)
{
    // 여러분들이 건드려야 하는 부분은 여기 뿐입니다.

    // 1. 플레이어의 무기의 강화 상태를 보여준다.
    // 기존 그려졌던 랜더링을 전부다 지우고.
    // 1번선택지는 강화
    // 2번선택지는 나간다.
    // 30강에 도달한 무기는 강화가 안 된다고 띄워라.

    system("cls");

    while (true) {
        _Player.StatusRender();
        //무기 강화 상태 보여주기
        _Player.Weapon.EquipRender();


        if (_Player.Weapon.GetEquipUp() >= 30) {
            printf_s("무기가 최대 레벨입니다.\n");
            printf_s("1. 나간다.\n");

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

        printf_s("무기를 강화 하시겠습니까.\n");
        printf_s("1. 강화.\n");
        printf_s("2. 나간다.\n");
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
                printf_s("골드가 부족합니다.\n");
                printf_s("1. 나간다.\n");

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

    // 2.번
    // 1강부터 10강까지는 실패해도 강화수치가 떨어지지 않습니다.
    // 10강부터 20강까지는 실패하면 강화수치가 5씩 떨어집니다.
    // 20강부터 30강까지는 실패하면 강화수치가 0이 됩니다.
    // 강화확률 마음대로
}

void Town::Heal(Player& _Player)
{
    system("cls");

    while (true) {
        _Player.Heal();
        _Player.StatusRender();
        printf_s("%s가 치료되었습니다.\n", _Player.GetName());

        printf_s("1. 나간다.\n");
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
        printf_s("마을에서 무엇을 하시겠습니까.\n");
        printf_s("1. 강화.\n");
        printf_s("2. 치료.\n");
        printf_s("3. 나간다.\n");
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
