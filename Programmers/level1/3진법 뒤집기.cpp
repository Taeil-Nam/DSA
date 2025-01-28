#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
    vector<int> base3;
    int powers = 0;
    int answer = 0;
    
    for (; n > 0; n /= 3)
        base3.push_back(n % 3);
    
    for (int i = base3.size() - 1; i >= 0; i--)
    {
        answer += base3[i] * pow(3, powers);
        powers++;
    }   
    
    return answer;
}
