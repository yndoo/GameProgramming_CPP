#pragma once
#include <Windows.h>
#include <assert.h>

#define MsgBoxAssert(TEXT) MessageBoxA(nullptr, TEXT, "치명적 에러", MB_OK); assert(false);  // 프로그램을 파괴할 수 있는 함수 Assert

#define LeakCheck	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF)

