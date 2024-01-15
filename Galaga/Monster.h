#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Monster : public ConsoleObject
{
protected:
	void Update() override;

private:
	int2 Dir = Right;
	int Count = 11;
};

