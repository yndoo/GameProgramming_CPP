// DanglingPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	
	int* Ptr = new int();
	
	delete Ptr;

	if (nullptr != Ptr) {
		*Ptr = 30;;
	}


	int a = 0;
}
