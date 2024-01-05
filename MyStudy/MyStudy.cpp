#include<Windows.h>
#include<assert.h>

#define MsgAssert(TEXT) MessageBoxA(nullptr, TEXT, "치명적 에러", MB_OK); assert(false);  // 프로그램을 파괴할 수 있는 함수 Assert

int main()
{   
    MsgAssert("화면 크기가 0입니다.");
    return 0;
}