#include <string>
#include <vector>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    int len = p.size();
    unsigned long long num = stoull(p);
    
    for (int i = 0; i <= t.size() - len; i++)
    {
        string temp;
        for (int j = 0; j < len; j++)
        {
            temp.push_back(t[i + j]);
        }
        if (stoull(temp) <= num)
            answer++;
    }
    
    return answer;
}
