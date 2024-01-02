// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

class int2
{
	// 보통 이런 수학적 클래스는
	// public으로 맴버변수를 두는 편입니다.
public:
	int X = 0;
	int Y = 0;
};

// 이런걸 정의하는것을 좋아하지는 않습니다.
// typedef int2 Pos;

// 전역변수는 영역과 관련없이
// 이름이 위에 있다면 그것을 사용할 수 있다.
const int ScreenX = 20;
const int ScreenY = 10;
const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;

class Bullet {
public:
	void SetBullet(const int2& _Pos) {
		Pos = _Pos;
	}
	int2 GetBulletPos() {
		return Pos;
	}
private:
	int2 Pos = { 0,0 };
};


class ConsoleScreen
{
public:
	// 생성자를 만든다는 것은
	// 내가 만든 생성자 형식으로만 생성해라.
	ConsoleScreen(char _BaseChar)
	{
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]

		BaseCh = _BaseChar;

		for (int y = 0; y < ScreenY; y++)
		{
			for (int x = 0; x < ScreenX - 1; x++)
			{
				Arr[y][x] = BaseCh;
			}
		}
	}

	void PrintScreen()
	{
		for (int y = 0; y < ScreenY; y++)
		{
			char* Ptr = Arr[y];
			printf_s(Ptr);
			printf_s("\n");
		}
	}

	void ClearScreen()
	{
		system("cls");
		for (int y = 0; y < ScreenY; y++)
		{
			for (int x = 0; x < ScreenX - 1; x++)
			{
				if ((y == 0 || y == ScreenY - 1) || (x == 0 || x == ScreenX - 2)) {
					Arr[y][x] = '#';
				}
				else {
					Arr[y][x] = BaseCh;
				}
			}
		}
	}

	void CreateBullet(const int2& _Bullet) {
		if (_Bullet.X != 0 && _Bullet.Y != 0) {
			Arr[_Bullet.Y - 1][_Bullet.X] = '|';
		}
	}

	void SetPixel(const int2& _Position, char _Char)
	{
		SetPixel(_Position.X, _Position.Y, _Char);
	}

	void SetPixel(int _X, int _Y, char _Char)
	{
		Arr[_Y][_X] = _Char;
	}

protected:

private:
	char Arr[ScreenY][ScreenX] = { 0, };
	char BaseCh = ' ';
	//int2 Bullet = { 0, 0 };

	//ScreenY가 5일 때
	//0 [0][0][0][0][0][0]
	//1 [0][0][0][0][0][0]
	//2 [0][0][0][0][0][0]
	//3 [0][0][0][0][0][0]
	//4 [0][0][0][0][0][0]
};

class Player
{
public:
	Player()
	{
	}

	Player(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{
	}

	// inline은 컴파일러가 함수를 삭제하고
	// 그 위치에 치환시켜 버린다.
	inline int2 GetPos()
	{
		return Pos;
	}

	inline char GetRenderChar()
	{
		return RenderChar;
	}

	void ClearScreen()
	{
		system("cls");
	}


	void Update(char ch)
	{
		// getch의 리턴값을 확인해서
		// 상하좌우로 움직이게 하세요.
		
		//char ch = _getch();
		//ClearScreen();
		switch (ch) {
		case 'w':
		case 'W':
			if (Pos.Y - 1 > 0) {
				Pos.Y -= 1;
			}
			break;
		case 's':
		case 'S':
			if (Pos.Y + 1 < ScreenY - 1) {
				Pos.Y += 1;
			}
			break;
		case 'a':
		case 'A':
			if (Pos.X - 1 > 0) {
				Pos.X -= 1;
			}
			break;
		case 'd':
		case 'D':
			if (Pos.X + 1 < ScreenX - 2) { // X는 문자열의 끝에 0이 둘 자리가 있어야해서 하나 더 작음
				Pos.X += 1;
			}
			break;
		default:
			break;
		}
		// 입력값이 w면 위로 y - 1
		// 입력값이 s면 아래로 y + 1
		// a면 왼쪽으로 x - 1
		// d면 오른쪽으로 x + 1

	}

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};

int main()
{
	ConsoleScreen NewScreen = ConsoleScreen('*');
	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');
	Bullet NewBullet = Bullet();

	while (true)
	{
		NewScreen.ClearScreen();
		NewScreen.SetPixel(NewPlayer.GetPos(), NewPlayer.GetRenderChar());
		NewScreen.CreateBullet(NewBullet.GetBulletPos());
		NewScreen.PrintScreen();
;		char ch = _getch();
		if (ch == ';') {
			NewBullet.SetBullet(NewPlayer.GetPos());
		}
		else {
			NewPlayer.Update(ch);
		}
	}
}
