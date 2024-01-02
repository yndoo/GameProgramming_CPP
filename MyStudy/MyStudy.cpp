#include <iostream>

class FightUnit {
public:
	//virtual 문법 : 자식이 만약 나와 완전히 동일한 함수를 구현한다면(override) 자식의 함수를 우선적으로 실행한다.
	virtual int GetAtt() {
		return Att;
	}
private:
	int Att = 10;
};

class Monster :public FightUnit {

};

class Player :public FightUnit {
public:
	int WeaponAtt = 10;
protected:
	// override 붙여서 부모에게 물려받은 함수를 재구현한 함수라는 것을 명시한다. (안 붙여도 의도대로 동작됨)
	int GetAtt() override {
		return FightUnit::GetAtt() + WeaponAtt; // 여기서의 GetAtt()는 내 함수로 인식됨.
	}
};

void Fight(FightUnit* Left, FightUnit* Right) {
	// 겉으로 볼때는 FightUnit지만 동작할 때는 플레이어나 몬스터처럼 동작한다. 그래서 다형성이라고 한다.
	int Value0 = Left->GetAtt();	// 20	
	int Value1 = Right->GetAtt();	// 10

}
int main() {

	Player NewPlayer;
	Monster NewMonster;
	
	Fight(&NewPlayer, &NewMonster);

	return 0;
}