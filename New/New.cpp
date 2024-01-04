#include <iostream>

class Zone {

};
class Monster {
	int Att;
	int Hp;
};
int main()
{
	//Zone Arr[100];
	// new 연산자를 붙이면 Zone을 하나 생성하겠다는 의미.
	//Zone* CurZone = nullptr;

	//CurZone = new Zone;

	// 무조건 프로그램 시작에 놔야 함.
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	//Monster* NewMonster = new Monster();
	int MonsterCount = 10;
	int PlayerLevel = 30;

	if (PlayerLevel > 20)
	{
		MonsterCount = 30;
	}

	Monster* NewMonster = new Monster[MonsterCount];
	Monster* NewMonsterArr = NewMonster;

	//delete NewMonsterArr;
	delete NewMonster;

}

