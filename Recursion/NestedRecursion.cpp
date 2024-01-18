#include <iostream>

// Nested Recursion은 재귀 함수의 매개 변수로 재귀를 사용하는 것을 말한다.
int NestedRecursion(int number)
{
	if (number > 100)
	{
		return number - 10;
	}
	else
	{
		return NestedRecursion(NestedRecursion(number + 11));
	}
}

int main()
{
	int number = 98;

	std::cout << NestedRecursion(number) << std::endl;

	return 0;
}
