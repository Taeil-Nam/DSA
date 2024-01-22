#include <iostream>

// Taylor Serires = 1 + (n^1 / 1!) + (n^2 / 2!) + (n^3 / 3!) ...
long TaylorSeries(int number, int time)
{
	static long power = 1;
	static long factorial = 1;
	long beforeResult = 0;

	if (time <= 0)
	{
		return 1;
	}
	else
	{
		beforeResult = TaylorSeries(number, time - 1);
		power = power * number;
		factorial = factorial * time;
		return beforeResult + (power / factorial);
	}
}

int main()
{
	int number = 2;
	int time = 10;
	// 1 + 2 + 2 + 1 + 0 + 0 + 0 ... = 6.

	std::cout << TaylorSeries(number, time) << std::endl;

	return 0;
}
