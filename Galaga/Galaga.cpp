#include <iostream>
#include <ConsoleEngine/ConsoleScreen.h>

int main()
{
    LeakCheck;
    ConsoleScreen NewScreen = ConsoleScreen();
    NewScreen.CreateScreen(10, 10);
    while (true) {
        NewScreen.PrintScreen();
        Sleep(1000);
    }
    NewScreen.ReleaseScreen();
}
