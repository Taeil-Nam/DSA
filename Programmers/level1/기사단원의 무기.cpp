#include <cmath>

using namespace std;

int GetDivisorCount(int number)
{
    int count = 0;

    for (int divisor = 1; divisor <= sqrt(number); divisor++)
    {
        if (number % divisor == 0)
        {
            count++;
            if (divisor != number / divisor)
                count++;
        }
    }

    return count;
}

int solution(int number, int limit, int power)
{
    int answer = 0;
    int divisorCount = 0;
    
    for (int knight = 1; knight <= number; knight++)
    {               
        divisorCount = GetDivisorCount(knight);
        if (divisorCount > limit)
            answer += power;
        else
            answer += divisorCount;
    }
    
    return answer;
}
