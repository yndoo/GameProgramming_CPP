#include <iostream>

class FightUnit
{
public:
    virtual void Damage()
    {

    }
    virtual void StatusRender() {

    }
};

class Player : public FightUnit
{
public:
    void Damage() override
    {

    }
};
enum Job {
    Fighter,    //Job::Fighter = 0
    Mage,
};

enum class DamageType {
    PDamage,
    MDamage
};

int main()
{
    int Size = sizeof(FightUnit);

    int a = 0;

    int Arr[10];
    int* Ptr = Arr;
    int* ArrPtr[10]; 
    int Size2 = sizeof(ArrPtr); // 80

    int** Ptr2D = ArrPtr;

    int const* const* Ptrr = ArrPtr; // 8
    int Size3 = sizeof(Ptrr);
    int b = 0;

    // 이렇게 사용 가능
    Job Fighter = Job::Fighter;

    // 형변환으로 확인
    int FighterInt = Job::Fighter;  // 0
    int MageInt = Job::Mage;        // 1

    DamageType Type = DamageType::MDamage;

    int Value = Type;

    return 0;
}