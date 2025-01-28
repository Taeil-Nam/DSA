#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    vector<int> counts(n, 0);
    int person = 0;
    int cycle = 0;
    char firstC = 0;
    char lastC = 0;
    bool isFinish = false;
    
    for (size_t i = 0; i < words.size(); i++)
    {
        counts[person]++;
        firstC = words[i][0];
        if (cycle != 0 && firstC != lastC)
        {
            answer.push_back(person + 1);
            answer.push_back(counts[person]);
            isFinish = true;
        }
        for (size_t j = 0; j < i; j++)
        {
            if (words[i] == words[j])
            {
                answer.push_back(person + 1);
                answer.push_back(counts[person]);
                isFinish = true;
            }
        }
        if (isFinish == true)
            break;
        lastC = words[i][words[i].length() - 1];
        person++;
        if (person >= n)
            person = 0;
        cycle++;
    }
    
    if (isFinish == false)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
