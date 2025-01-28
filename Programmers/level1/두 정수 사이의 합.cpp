#include <string>
#include <vector>
#include <limits.h>

using namespace std;

long long solution(int a, int b) {
    long long sum = 0;
    int max_num = INT_MIN;
    int min_num = INT_MAX;
    
    if (a > b)
    {
        max_num = a;
        min_num = b;
    }
    else
    {
        max_num = b;
        min_num = a;
    }
    
    for (int n = min_num; n <= max_num; n++)
    {
        sum += n;
    }
    
    return sum;
}
