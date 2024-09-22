#include <iostream>

void TreeRecursion(int number)
{
	if (number > 0)
	{
		std::cout << number << std::endl;
		TreeRecursion(number - 1);	// Tree Recursion.
		TreeRecursion(number - 1);	// Tree Recursion.
	}
}

// Tree Recursion은 2개 이상의 재귀 함수를 호출하는 것을 말한다.
// Time Complexity = 재귀 함수 호출 횟수이므로 O(2^n) 이다. 정확히는 2^(n+1) - 1.
// Space Complexity = 필요한 최대 스택 프레임의 개수(Tree의 level 개수) 이므로 O(n) 이다. 정확히는 n + 1.

int main()
{
	int number = 3;

	TreeRecursion(number);

	return 0;
}
