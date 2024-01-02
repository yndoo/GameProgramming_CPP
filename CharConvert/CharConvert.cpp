#include <iostream>

int CharConvert(char* _String, char _PrevCh, char _NextCh)
{
    // 바뀐 글자수를 리턴합니다.
    int Result = 0; // 바뀐 글자수 세기
    int index = 0; // 인덱스
    while (_String[index]) {
        if (_String[index] == _PrevCh) {
            _String[index] = _NextCh;
            Result++;
        }
        index++;
    }

    return Result;
}

int main()
{
    char Arr[10] = "aaabbbccb";

    int Result = CharConvert(Arr, 'b', 'd'); //두번째 문자를 세번째 문자로 바꾸기.
    // "aaadddccc"

    return 0;
}