#include <iostream>

void TailRecursion(int number)
{
	if (number > 0)
	{
		std::cout << number << std::endl;
		TailRecursion(number - 1);	// Tail Recursion.
	}
}

// Tail Recursion은 반복문으로 변환이 가능하다.
// 재귀 함수는 함수 호출마다 스택 메모리를 할당받기 때문에, space complexity = O(n) 이다. (n = 함수 호출 횟수)
// 따라서, Tail Recursion을 사용하기보다 반복문을 사용하는게 더 효율적이다.
void TailRecursionToLoop(int number)
{
	while (number > 0)
	{
		std::cout << number << std::endl;
		number--;
	}
}

int main()
{
	int number = 5;

	TailRecursion(number);
	TailRecursionToLoop(number);
	return 0;
}
