#pragma once
#include "ConsoleMath.h"

// ���漱�� 
class ConsoleObject
{
	friend class EngineCore;

public:
	ConsoleObject();
	ConsoleObject(const int2& _StartPos, char _RenderChar);
	// �Ҹ��� virtual 
	virtual ~ConsoleObject();

	int2 GetPos() const;
	char GetRenderChar() const;

	inline void SetRenderChar(char _Ch)
	{
		RenderChar = _Ch;
	}

	inline void SetPos(const int2& _Pos)
	{
		Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir)
	{
		Pos += _Dir;
	}

	virtual void Update()
	{

	}

	void Destroy()
	{
		DeathValue = true;
	}

	bool IsPendingKill()
	{
		return DeathValue;
	}

	class EngineCore* GetCore()
	{
		return Core;
	}

	template<typename EnumType>
	ConsoleObject* Collision(EnumType _UpdateOrder)
	{
		return Collision(static_cast<int>(_UpdateOrder));
	}

	// ���� �浹�� ������Ʈ
	ConsoleObject* Collision(int _UpdateOrder);
	// std::list<ConsoleObject*> CollisionList(int _UpdateOrder);

protected:

private:
	bool DeathValue = false;

	int2 Pos = { 0, 0 };
	char RenderChar = '@';
	class EngineCore* Core = nullptr;

	void SetCore(EngineCore* _Core)
	{
		Core = _Core;
	}
};


