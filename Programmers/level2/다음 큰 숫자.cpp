#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int GetBinCount(int n)
{
    int binCount = 0;
    
    while (n != 0)
    {
        if (n % 2 == 1)
            binCount++;
        n /= 2;
    }

    return binCount;
}

int solution(int n)
{
    int answer = 0;
    int binCount = 0;
    
    binCount = GetBinCount(n);
    for (int targetNum = n + 1; targetNum <= INT32_MAX; targetNum++)
    {
        if (GetBinCount(targetNum) == binCount)
        {
            answer = targetNum;
            break;
        }
    }
    
    return answer;
}
