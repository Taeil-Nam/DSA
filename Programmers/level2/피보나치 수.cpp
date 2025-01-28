#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int a = 0;
    int b = 1;
    int sum = 0;
    
    for (int num = 1; num < n; num++)
    {
        sum = (a + b) % 1234567;
        a = b;
        b = sum;
    }
    
    return sum;
}
