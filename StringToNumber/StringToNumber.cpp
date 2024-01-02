#include <iostream>

int StringCount(const char* const _Ptr)
{
    int Count = 0;
    while (_Ptr[Count])
    {
        ++Count;
    }
    return Count;
}

void NumberToString(int Number, char* _Ptr) {
    int count = 0;
    int num = Number;
    // count 구하기
    // 맨 앞에 0이 들어가면 count가 잘못됨!!!!!!!!!!! 
    // 맨 앞에 0이 붙으면 8진수라서 그럼... 10진수만 생각하면 될듯?
    while (num) {
        num /= 10;
        count++;
    }
    // 뒷자리부터 채우기
    //while (Number) {
    //    int ch = Number % 10;
    //    _Ptr[count - 1] = ch + '0';
    //    count--;
    //    Number /= 10;
    //}
    // while문으로 돌면 맨 앞이 0이면 끝나버림
    for (int i = count - 1; i >= 0; i--) {
        int ch = Number % 10;
        _Ptr[i] = ch + '0';
        Number /= 10;
    }
}

void NumberToString2(int Number, char* _Ptr) {
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


int StringToNumber(const char* const _NumberString)
{
    // 글자 개수를 알아내야 합니다.
    // StringCount();
    // * 10 써야 합니다.
    // / 10 써야 합니다.
    // = 변수 - '0' 사용.
    // for문을 사용해야합니다.
    // 예외처리 안합니다.

    // char Ch = _NumberString[0];

    int result = 0;
    int count = StringCount(_NumberString);

    int power = 1;
    for (int j = 0; j < count; j++) {
        power *= 10;
    }

    for (int i = 0; i < count; i++) {
        int ch = _NumberString[i] - '0';
        power /= 10;
        result += ch * power;
    }

    return result;
}

int main()
{
    int Number = StringToNumber("123454321"); // 문자열이 그대로 숫자가 되어 나오는 함수를 만들면 됨
    char Arr[100] = {};
    NumberToString2(2345, Arr);
    return 0;
}
