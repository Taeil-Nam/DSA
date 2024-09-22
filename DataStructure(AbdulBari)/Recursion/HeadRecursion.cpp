#include <iostream>

void HeadRecursion(int number)
{
	if (number > 0)
	{
		HeadRecursion(number - 1);	// Head Recursion.
		std::cout << number << std::endl;	// 1, 2, 3, 4, 5
	}
}

// Head Recursion은 반복문으로 변환이 가능하다.
// 그러나, Tail Recursion과는 다르게 반복문으로 변환할 때 추가적인 작업이 더 필요하다.
// 즉, Tail Recursion을 제외한 다른 Recursion은 반복문으로 변환이 가능하지만, 추가적인 작업이 더 필요하다.
void HeadRecursionToLoop(int number)
{
	int i = 1;
	while (i <= number)
	{
		std::cout << i << std::endl;
		i++;
	}
}

int main()
{
	int number = 5;

	HeadRecursion(number);
	HeadRecursionToLoop(number);
	return 0;
}
