// StringTrim.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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

// _Start번째부터 전부다 왼쪽으로 한칸이동
void LeftMoveString(char* _Ptr, int _Start)
{
    char NewArr[100] = {};
    int Count = StringCount(_Ptr);

    for (int i = 0; i < _Start - 1; i++) {
        NewArr[i] = _Ptr[i];
    }

    for (int i = _Start - 1; i < Count; i++) {
        NewArr[i] = _Ptr[i + 1];
    }

    // 전체 복사해주기
    for (int i = 0; i < Count; i++) {
        _Ptr[i] = NewArr[i];
    }
}

// _Start번째부터 전부다 왼쪽으로 한칸이동
void LeftMoveString2(char* _Ptr, int _Start)
{
    // 이것도 방어 코드
    if (_Ptr == nullptr) {
        return;
    }
    int Count = StringCount(_Ptr);
    // 방어 코드
    if (_Start == 0) {
        _Start = 1;
    }

    for (int i = _Start - 1; i < Count; i++) {
        _Ptr[i] = _Ptr[i + 1];
    }
}

// _DeleteCh를 지우기
void DeleteChar(char* _Ptr, char _DeleteCh)
{
    int Count = StringCount(_Ptr);
    for (int i = 0; i < Count; i++) {
        if (_Ptr[i] == _DeleteCh) {
            LeftMoveString(_Ptr, i + 1);
            i--; // 왼쪽으로 옮기고 나면 글자수 전체가 줄기 때문에 i를 같이 땡겨줘야함.
        }
    }

}


int main()
{

    {
        char Arr[100] = "abcde";
        LeftMoveString2(Arr, 2);
        // "abcde";
        int a = 0;
    }

    {
        char Arr[100] = "a b c d e";
        DeleteChar(Arr, 'b');
        // Arr = abcde
        int a = 0;
    }

    return 0;
}
