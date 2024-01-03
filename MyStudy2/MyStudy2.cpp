#include <iostream>

// 자료형에 별명 붙여주는 게 typedef였음
typedef int int32;

enum class Job {
	Fighter,
};

// 가능
typedef Job JobType;

// typedef가 문법적으로 아름답지 못하다 생각해서 using도 만듦, typedef랑 다른 게 없다.
using myint = int;

namespace UI {
	class Item {

	};
}

namespace Play {
	class Monster
	{
		class Item {

		};
	};
}

// 헤더 (.h)
namespace std {
	class MyStream {
	public:
		void operator <<(const char* _Text) {
			printf_s(_Text);
		}
	};
	// 전역 객체
	extern MyStream mycout;
}

// (.cpp)
std::MyStream mycout;

int main() {
	UI::Item NewUIItem;
	//Play::Monster::Item NewPlayItem;

	std::mycout << "Hello World!\n";
}