#include <iostream>

int main()
{
	char Arr[100] = "ddddsfsdfwefwefwe";

	FILE* Ptr;

	fopen_s(&Ptr, "aaaa.txt", "wt");

	// �� ���̿��� ������ �ϸ� ���Ͽ� �����.
	fwrite(Arr, 100, 1, Ptr);

	fclose(Ptr);
}