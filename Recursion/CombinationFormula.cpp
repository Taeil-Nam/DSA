#include <iostream>

// Combination Formula = nCr = n! / (r! x (n-r)!)
long Combination(int n, int r)
{
	if (r <= 0 || r >= n)
	{
		return 1;
	}
	return Combination(n - 1, r - 1) + Combination(n - 1, r);
}

int main()
{
	int n = 5;
	int r = 3;

	std::cout << Combination(n, r) << std::endl;

	return 0;
}
