#include <iostream>

struct MyStruct {
	int A;
	int B;
};

union MyUnion {
	int A;
	char Arr[4];
};

struct float4 
{
	union 
	{
		struct 
		{
			float X;
			float Y;
			float Z;
			float W;
		};
		float Arr1D[4];
	};
};

void Test() {
	static int A = 0;
	std::cout << ++A << std::endl;
}

int main() {
	bool tmp;

	int a = 0;
}