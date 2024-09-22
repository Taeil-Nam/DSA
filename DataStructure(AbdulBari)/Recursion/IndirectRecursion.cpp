#include <iostream>

void IndirectRecursionA(int number);
void IndirectRecursionB(int number);

// IndirectRecursion은 자기 자신을 호출 하는 것이 아닌, 다른 함수에 의해 재귀적으로 호출되는 것을 말한다.
void IndirectRecursionA(int number)
{
	if (number > 0)
	{
		std::cout << number << std::endl;
		IndirectRecursionB(number - 1);
	}
}

void IndirectRecursionB(int number)
{
	if (number > 0)
	{
		std::cout << number << std::endl;
		IndirectRecursionA(number / 2);
	}
}

int main()
{
	int number = 5;

	IndirectRecursionA(number);

	return 0;
}
