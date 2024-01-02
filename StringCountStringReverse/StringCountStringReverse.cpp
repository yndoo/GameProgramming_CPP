#include <iostream>

int StringCount(char* _Ptr) {
    int Count = 0;
    while (*(_Ptr + Count)) {
        Count++;
    }
    return Count;
}

int StringReverse(char* _Ptr) {
    int Length = StringCount(_Ptr);
    int HalfLength = Length / 2;

    for (int i = 0; i < HalfLength; i++) {
        char tmp = _Ptr[i];
        _Ptr[i] = _Ptr[Length - i - 1];
        _Ptr[Length - i - 1] = tmp;
    }
    return 0;
}

int main()
{
    {
        char Arr[10] = "123456789";
        int Result = StringCount(Arr); // Result에 문자열의 글자 수가 나오도록(마지막 0 제외)
        int a = 0;
    }
    {
        char Arr[10] = "ABCDEFGH";
        StringReverse(Arr); // Arr에 문자열이 뒤집어서 들어가도록
        int a = 0;
    }
    return 0;
}
