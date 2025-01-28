#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int num = 0;

    for (int i = 1; i <= n; i++)
    {
        num = 0;
        for (int j = i; j <= n; j++)
        {
            num += j;
            if (num == n)
            {
                answer++;
                break;
            }
            else if (num > n)
                break;
        }
    }
    
    return answer;
}
