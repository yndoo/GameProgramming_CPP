#include <iostream>
#include <list>
#include <map>

int main() {
	std::list<int> NewList;
	for (int Value : NewList) {

	}
	// 레퍼런스로 수정하고 싶다면
	for (int& Value : NewList) {

	}

	std::map<int, int> NewMap;
	for (std::pair<const int, int>& Map : NewMap) {

	}
}