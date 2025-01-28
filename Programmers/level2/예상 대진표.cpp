#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int cycle = 1;
    float fa = a;
    float fb = b;

    for (; n != 1; n /= 2)
    {
        if (roundf(fa / 2) == roundf(fb / 2))
            return cycle;
        fa = roundf(fa / 2);
        fb = roundf(fb / 2);
        cycle++;
    }
}
