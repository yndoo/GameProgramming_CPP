#include <iostream>

int main(int Count, char** _Ptr) 
{
	for (size_t i = 0; i < Count; i++) 
	{
		std::cout << _Ptr[i] << std::endl;
	}
}