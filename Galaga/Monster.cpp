#include "Monster.h"
#include "ContentsEnum.h"
#include "ConsoleEngine/EngineCore.h"


void Monster::Update()
{
	//int2 CurPos = GetPos();

	//if (CurPos.Y % 2 == 0) {
	//	if (CurPos.X >= 19) {
	//		AddPos(Down);
	//	}
	//	else {
	//		AddPos(Right);
	//	}
	//}
	//else if (CurPos.Y % 2 == 1) {
	//	if (CurPos.X <= 0) {
	//		AddPos(Down);
	//	}
	//	else {
	//		AddPos(Left);
	//	}
	//}


	--Count;
	if (Count <= 0) {
		
		Dir.X *= -1;
		AddPos(Down);
		Count = 11;
	}
	else {
		AddPos(Dir);
	}

	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (GetPos().Y == 19) {
		Destroy();
		GetCore()->EngineEnd();
		//return;
	}


	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}

	ConsoleObject* CollisionObject2 = Collision(GalagaUpdateType::Player);
	if (nullptr != CollisionObject2)
	{
		Destroy();
		CollisionObject2->Destroy();
		GetCore()->EngineEnd();
	}

}