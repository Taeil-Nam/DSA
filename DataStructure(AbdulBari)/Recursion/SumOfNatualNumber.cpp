#include <iostream>

int Sum(int number)
{
	if (number == 1)
	{
		return number;
	}
	return number + Sum(number - 1);
}

int main()
{
	int number = 100;

	std::cout << Sum(number) << std::endl;

	return 0;
}