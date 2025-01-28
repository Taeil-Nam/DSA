#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food)
{
    string answer = "";
    char c;

    for (int i = 1; i < food.size(); i++)
    {
        c = i + '0';
        for (int j = 0; j < food[i] / 2; j++)
        {
            answer.push_back(c);
        }
    }
    answer.push_back('0');
    for (int i = food.size() - 1; i > 0; i--)
    {
        c = i + '0';
        for (int j = 0; j < food[i] / 2; j++)
        {
            answer.push_back(c);
        }
    }
    return answer;
}
