#include <iostream>

// 선생님이 기본적으로 함수의 인자는 => 지역변수
// 지역변수와 약간 다른점이 있습니다.
void Test(int _Value0, int _Value1, int _Value2, int _Value3)
{
    __int64 Address0 = reinterpret_cast<__int64>(&_Value0);
    __int64 Address1 = reinterpret_cast<__int64>(&_Value1);
    __int64 Address2 = reinterpret_cast<__int64>(&_Value2);
    __int64 Address3 = reinterpret_cast<__int64>(&_Value3);

    // 8바이트씩 차이남
}


int main()
{
    Test(10, 20, 30, 40);
}
