#include <iostream>

using namespace std;

long long fibo(long long n)
{
    if (n == 0 || n == 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    cout << fibo(20) << endl;

    return 0;
}