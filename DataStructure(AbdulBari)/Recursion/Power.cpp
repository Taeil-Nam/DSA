#include <iostream>

long Power(int number, int power)
{
	if (power <= 0)
	{
		return 1;
	}
	return number * Power(number, power - 1);
}

// 반복문 버전
//long Power(int number, int power)
//{
//	long result = 1;
//	int i = 0;

//	if (power == 0)
//	{
//		return 1;
//	}
//	while (i < power)
//	{
//		result *= number;
//		i++;
//	}
//	return result;
//}

int main()
{
	int number = 2;
	int power = 5;

	std::cout << Power(number, power) << std::endl;

	return 0;
}
