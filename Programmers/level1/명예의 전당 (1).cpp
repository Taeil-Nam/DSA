#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    vector<int> best;
    
    for (int i = 0; i < score.size(); i++)
    {
        if (i < k)
            best.push_back(score[i]);
        else
        {
            if (score[i] > best[0])
                best[0] = score[i];
        }
        sort(best.begin(), best.end());
        answer.push_back(best[0]);
    }
    
    return answer;
}
