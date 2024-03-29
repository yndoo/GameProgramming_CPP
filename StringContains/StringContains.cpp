﻿#include <iostream>

enum class StringReturn
{
    Equal,
    NotEqual
};

int StringCount(const char* const _Ptr)
{
    int Count = 0;
    while (_Ptr[Count])
    {
        ++Count;
    }
    return Count;
}

StringReturn StringEqual(const char* const _Left, const char* const _Right)
{
    int LeftCount = 0;
    int RightCount = 0;
    LeftCount = StringCount(_Left);
    RightCount = StringCount(_Right);
    if (LeftCount != RightCount) {
        return StringReturn::NotEqual;
    }
    else {
        // 글자 수가 같으면 진짜 같은지 체크
        for (int i = 0; i < LeftCount; i++) {
            if (_Left[i] != _Right[i]) {
                //하나라도 다른 게 있으면 바로 NotEqual 리턴
                return StringReturn::NotEqual;
            }
        }
        // 여기까지 왔다면 모두 같은 것이므로 Equal 리턴
        return StringReturn::Equal;
    }
}

void StringAdd(char* _Dest, const char* const _Left, const char* const _Right)
{
    int LeftCount = 0;
    int RightCount = 0;
    LeftCount = StringCount(_Left);
    RightCount = StringCount(_Right);
    for (int i = 0; i < LeftCount; i++) {
        _Dest[i] = _Left[i];
    }
    for (int i = LeftCount; i < LeftCount + RightCount; i++) {
        _Dest[i] = _Right[i - LeftCount];
    }
    _Dest[LeftCount + RightCount] = 0;
    return;
}

int StringContains(const char* const _Dest, const char* const _Find)
{
    int DestCount = StringCount(_Dest);
    int FindCount = StringCount(_Find);
    int Result = 0;

    for (int i = 0; i < DestCount; i++) {
        bool CheckFlag = true;
        for (int j = 0; j < FindCount; j++) {
            if (_Dest[i + j] != _Find[j]) {
                CheckFlag = false;
            }
        }
        if (CheckFlag == true) {
            Result++;
        }
    }
    return Result;
}

int main()
{
    // StringCount 함수는 strlen()함수와 같음
    {
        // 오른쪽과 왼쪽이 같은지?
        StringReturn NewReturn1 = StringEqual("AAA", "AAAA");       // NotEqual
        StringReturn NewReturn2 = StringEqual("ABC123", "ABC123");  // Equal
        int NewReturn3 = strcmp("ABC123", "ABC123");                // 0
        int NewReturn4 = strcmp("ABC123", "ABC");                   // 1

        //int Test = strcmp(nullptr, nullptr);
        int a = 0;

        // strcmp()와 같은 함수
    }

    {
        char Arr[100] = "aaaaaaaaaaaaaaaaa";
        StringAdd(Arr, "hello", "world");

        // sprintf_s 함수로 같은 기능 사용 가능
        char ArrTest[100];
        sprintf_s(ArrTest, "%s%s", "AAAA", "BBBB");
        int a = 0;
    }

    {
        int Result1 = StringContains("ababcccccabab", "ab");    // 4
        int Result2 = StringContains("ababcccccabab", "c");     // 5
        int a = 0;
    }
}