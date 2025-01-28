#include <string>
#include <vector>

using namespace std;

long long solution(long long n)
{
	if (n == 1)
		return 4;

	for (long long x = 2; x <= n / x; x++)
	{
		if ((x == n / x) && (n % x == 0))
			return (x + 1) * (x + 1);
	}
	return (-1);
}