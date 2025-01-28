#include <string>
#include <vector>

using namespace std;

void Hanoi(int topSize, int a, int b, int c, vector<vector<int>>& answer)
{
    if (topSize > 0)
    {
        Hanoi(topSize - 1, a, c, b, answer);
        answer.push_back({a, c});
        Hanoi(topSize - 1, b, a, c, answer);
    }
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;
    
    Hanoi(n, 1, 2, 3, answer);
    
    return answer;
}
