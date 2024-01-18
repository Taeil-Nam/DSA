#include <iostream>

int Factorial(int number)
{
	if (number <= 0)
	{
		return 1;
	}
	return number * Factorial(number - 1);
}

int main()
{
	int number = 5;

	std::cout << Factorial(number) << std::endl;

	return 0;
}
