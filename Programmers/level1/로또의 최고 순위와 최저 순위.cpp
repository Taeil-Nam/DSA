#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int zeroCount = 0;
    int rank = 7;
    int lowRank = 7;
    int highRank = 7;

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zeroCount++;
            continue;
        }
        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == win_nums[j])
            {
                rank--;
                break;
            }
        }
    }

    lowRank = rank;
    for (int i = 0; i < zeroCount; i++)
    {
        if (lowRank < rank && lowRank < 6)
            lowRank++;
    }
    if (lowRank >= 7)
        lowRank = 6;

    highRank = rank;
    for (int i = 0; i < zeroCount; i++)
        highRank--;
    if (highRank >= 7)
        highRank = 6;
    
    answer.push_back(highRank);
    answer.push_back(lowRank);

    return answer;
}
