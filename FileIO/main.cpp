#include <iostream>

int main()
{
	char Arr[100] = "ddddsfsdfwefwefwe";

	FILE* Ptr;

	fopen_s(&Ptr, "aaaa.txt", "wt");

	// 이 사이에서 뭔가를 하면 파일에 적용됨.
	fwrite(Arr, 100, 1, Ptr);

	fclose(Ptr);
}