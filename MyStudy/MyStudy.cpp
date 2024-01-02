#include <iostream>

void Test() {
	printf("AAAAA");
}
int Test2() {
	return 10;
}

int main() {
	// 함수포인터 선언
	// 리턴형태 (*변수명) ()
	void(*Ptr)() = Test;
	int(*Ptr2)() = Test2;

	// 함수의 포인터이기 때문에 그 함수를 사용하는 방법 그대로 사용하게 된다.
	Ptr();	// "AAAAA"
}