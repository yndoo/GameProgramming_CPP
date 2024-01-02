#include <iostream>

// 전역

class Monster {
    // 클래스의 내부 : 멤버

public:
    int publicint;
    void publicFunction() {

    }

protected:
    int protectedint;
    void protectedFunction() {

    }
private:
	int privateint;
	void privateFunction() {

	}
};

class Player {

    void Damage(int _Att) {

    }
};


int main()
{
    // 지역(외부)
    Monster NewMonster = Monster();


    return 0;
}
