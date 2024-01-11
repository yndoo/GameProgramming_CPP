#include<iostream>
#include<vector>

class A {
	//특정 함수에 friend를 걸 수 있다.
	friend class B;
private:
	void TestA() {

	}
	int Value;
};
class B {
public:
	void Test(A& _Other) {
		_Other.Value;
		_Other.TestA();
	}
private:
	int Value;
	void BFunction(A& _Other) {
		_Other.Value;
	}

};

class C {
public:
	void Test(A& _Other) {
		//_Other.Value;
	}
};

int main()
{   

}