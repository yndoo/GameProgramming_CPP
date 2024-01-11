#include<iostream>

struct Monster {
public:
	Monster(int _Hp, int _Att)
		: Hp(_Hp), Att(_Att) {

	}

	void operator-(Monster _Other) {
		Hp -= _Other.Att;
	}
	int Hp;
	int Att;
};


int main()
{   
	Monster NewMonster = Monster(200, 10);
	Monster BadMonster = Monster(200, 20);

	NewMonster - BadMonster;

	std::cout << NewMonster.Hp << std::endl;
	std::cout << NewMonster.Att << std::endl;

}