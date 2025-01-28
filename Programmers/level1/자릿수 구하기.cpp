#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int mod = 0;

    for (; n != 0;)
    {
        mod = n % 10;
        n /= 10;
        answer += mod;
    }
    
    return answer;
}