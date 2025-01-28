#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> person1 = {1, 2, 3, 4, 5};
    vector<int> person2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> person3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> scores(3);
    int maxScore = 0;
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (person1[i % person1.size()] == answers[i]) scores[0]++;
        if (person2[i % person2.size()] == answers[i]) scores[1]++;
        if (person3[i % person3.size()] == answers[i]) scores[2]++;
    }
    maxScore = *(max_element(scores.begin(), scores.end()));
    for (int i = 0; i < 3; i++)
    {
        if (scores[i] == maxScore) answer.push_back(i + 1);
    }
    
    return answer;
}
