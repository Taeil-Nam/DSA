#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer = strings;
    vector<char> c;
    
    for (int i = 0; i  < strings.size(); i++)
        c.push_back(strings[i][n]);
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = i + 1; j < c.size(); j++)
        {
            if (c[i] > c[j])
            {
                swap(c[i], c[j]);
                swap(answer[i], answer[j]);
            }
            else if (c[i] == c[j])
            {
                if (answer[i].compare(answer[j]) > 0)
                {
                    swap(c[i], c[j]);
                    swap(answer[i], answer[j]);
                }
            }
        }
    }
    return answer;
}
