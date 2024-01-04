#include <iostream>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    {
        int Value = 0;
        int* Ptr = &Value;
    }
    {
        int* Ptr = new int(0);
    }

    new int(10);
    //reinterpret_cast<int*>(operator new(sizeof(int))); // new int()의 본모습
    
    return 0;
}