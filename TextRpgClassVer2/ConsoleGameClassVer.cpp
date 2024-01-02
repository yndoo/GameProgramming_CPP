#include <iostream>
#include "ConsoleScreen.h"
#include "Galaga.h"
#include "Player.h"
#include "Bullet.h"

int main()
{
	ConsoleScreen NewScreen = ConsoleScreen('*');
	Galaga NewGalaga = Galaga();

	Bullet NewBullet = Bullet({ 0,0 }, '^');
	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');

	bool& Ref = NewBullet.GetIsFireRef();
	NewPlayer.SetBulletFire(&Ref);

	while (true)
	{
		NewScreen.ClearScreen();
		NewGalaga.GalagaWallDraw(NewScreen);

		int2 Index = NewPlayer.GetPos();
		char Ch = NewPlayer.GetRenderChar();

		NewScreen.SetPixel(Index, Ch); //플레이어 위치에 플레이어 char 찍기

		if (true == NewBullet.GetIsFireRef())
		{
			NewBullet.SetPos({ NewPlayer.GetPos().X, NewPlayer.GetPos().Y - 1 });
			NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar()); //총알 위치에 총알 char 찍기
		}

		NewScreen.PrintScreen();
		NewPlayer.Update();
	}

}