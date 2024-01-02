#include <iostream>

void NumberToString(int Number, char* _Ptr) {
	//어떤 함수든 원본값을 보존해 놓는게 좋습니다.
	int CalNumber = Number;
	int NumberCount = 0;
	const char* CPtr = _Ptr;

	//정수가 몇자리인지 알아야 합니다.
	//10나누기를 합니다.

	while (CalNumber) {
		CalNumber /= 10;
		++NumberCount;
	}

	int power = 1;
	for (int j = 0; j < NumberCount - 1; j++) {
		power *= 10;
	}

	//숫자를 분해하기 시작
	//0 나누기가 허용되지 않는다.
	int Value = 0;
	CalNumber = Number;
	for (int i = 0; i < NumberCount; i++) {
		Value = CalNumber / power;
		_Ptr[i] = Value + '0';
		CalNumber -= Value * power;
		power /= 10;
	}
}

int MyPrintf(const char* const _Format, ...) {
	int Count = 0;
	__int64 Address = reinterpret_cast<__int64>(&_Format);
	while (_Format[Count]) {
		char Ch = _Format[Count];
		// 포맷팅이 아닐경우 글자를 출력하고 다시 반복한다.
		if (Ch != '%') {
			putchar(Ch);
			Count++;
			continue;
		}
		// 포맷팅 문자인 %를 만났을 경우.
		char NextCh = _Format[Count + 1];
		switch (NextCh) {
		case 'd':
		{
			// 인자를 끌어내야 합니다.
			//int* Ptr = reinterpret_cast<int*>(&_Format);	// 1. const char* const인데 값을 바꿀수있게되어버리므로 안됨 
															// 2. 바로 주소를 포인터로 바꾸는 것은 C스타일이라 안됨
			/*__int64 Address = reinterpret_cast<__int64>(&_Format);
			const int* Ptr = reinterpret_cast<int*>(Address);*/

			Address += 8;
			const int* Ptr = reinterpret_cast<int*>(Address);

			char Arr[100] = {};
			
			NumberToString(*Ptr, Arr);

			int Index = 0;
			while (Arr[Index]) {
				putchar(Arr[Index]);
				Count++;
				Index++;
			}
			break;
		}
		default:
		{
			int a = 0;
			break;
		}
		}
	}
	return Count;
}

int main()
{
	int Return = MyPrintf("aaabbb %d", 123); //aaabbb 123

	return 0;
}
