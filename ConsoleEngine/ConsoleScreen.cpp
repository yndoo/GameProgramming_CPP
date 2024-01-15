#include "ConsoleScreen.h"

// std �� �÷��� ���
#include <iostream>
#include <Windows.h>
#include <assert.h>
#include <conio.h>

// ��ü ���
#include "ConsoleObject.h"

ConsoleScreen::ConsoleScreen()
{

}
ConsoleScreen::~ConsoleScreen()
{
	ReleaseScreen();
}

void ConsoleScreen::CreateScreen(/*&NewScreen => this, */int _ScreenX, int _ScreenY)
{
	ReleaseScreen();

	if (0 >= _ScreenX)
	{
		MsgBoxAssert("��ũ�� Xũ�Ⱑ 0�̱� ������ �ܼ� ��ũ���� ����� �����ϴ�");
	}

	if (0 >= _ScreenY)
	{
		MsgBoxAssert("��ũ�� Yũ�Ⱑ 0�̱� ������ �ܼ� ��ũ���� ����� �����ϴ�");
	}

	/*this->*/ScreenX = _ScreenX;
	/*this->*/ScreenY = _ScreenY;

	if (0 != ScreenData.size())
	{
		MsgBoxAssert("�̹� ��ũ���� ���� ���¿��� �ٽ� ����������ϴ�");
	}

	// std::vector<char>* Ptr = new std::vector<char>[ScreenY];

	ScreenData.resize(ScreenY);
	// ScreenData = new char* [ScreenY];
	if (0 == ScreenData.size())
	{
		MsgBoxAssert("��ũ�� ������ �����߽��ϴ�. if (nullptr == ScreenData)");
	}

	for (int y = 0; y < ScreenY; y++)
	{
		ScreenData[y].resize(ScreenX + 2);
		// ScreenData[y] = new char[ScreenX + 2] {0,};

		if (0 == ScreenData[y].size())
		{
			MsgBoxAssert("��ũ�� ������ �����߽��ϴ�. if (nullptr == ScreenData[y])");
		}
	}

	ClearScreen();

	// �Լ��� ����Ǹ� ���ÿ� �� �Լ� �̸��� �޸𸮸� �׸���
	// �ɹ��Լ��� ����Ǹ� ���ο� this�� �ִٴ°��� ����ؾ� �Ѵ�.
	// new�� �ϸ� ������ �ʿ� ����. �ϴ� ������ �׷��� �Ѵ�.

}

void ConsoleScreen::ReleaseScreen()
{
	ScreenData.clear();

	// ���ﶧ�� �������� ������ �Ѵ�.
	//for (int y = 0; y < ScreenY; y++)
	//{
	//	if (nullptr == ScreenData[y])
	//	{
	//		continue;
	//	}

	//	delete[] ScreenData[y];
	//	ScreenData[y] = nullptr;
	//}

	//if (nullptr != ScreenData)
	//{
	//	delete[] ScreenData;
	//	ScreenData = nullptr;
	//}
}

void ConsoleScreen::SetChar(const ConsoleObject& _Object)
{
	SetChar(_Object.GetPos(), _Object.GetRenderChar());
}

void ConsoleScreen::SetChar(const ConsoleObject* _Object)
{
	SetChar(_Object->GetPos(), _Object->GetRenderChar());
}

void ConsoleScreen::SetChar(const int2& _Pos, char _Char)
{
	if (0 > _Pos.Y)
	{
		return;
	}

	if (0 > _Pos.X)
	{
		return;
	}

	if (ScreenX <= _Pos.X)
	{
		return;
	}

	if (ScreenY <= _Pos.Y)
	{
		return;
	}

	ScreenData[_Pos.Y][_Pos.X] = _Char;
}

void ConsoleScreen::ClearScreen()
{
	// char** ScreenData
	// char* ScreenData[0]
	// char ScreenData[0][0]

	// char** ScreenData
	// char* *ScreenData
	// char **ScreenData

	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX; x++)
		{
			ScreenData[y][x] = '*';
		}
		ScreenData[y][ScreenX] = '\n';
	}
}

void ConsoleScreen::PrintScreen()
{
	system("cls");

	for (int y = 0; y < ScreenY; y++)
	{
		if (0 == ScreenData[y].size())
		{
			MsgBoxAssert("�������� ���� ������ ����Ϸ��� �߽��ϴ�");
		}

		std::vector<char>& Vector = ScreenData[y];
		char& FirstChar = Vector[0];
		char* PrintPtr = &FirstChar;
		printf_s(PrintPtr);
	}

	ClearScreen();
}