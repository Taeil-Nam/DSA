#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score)
{
    int answer = 0;
    int boxCount = score.size() / m;
    int minScore = 0;

    sort(score.begin(), score.end());
    for (int count = 0; count < boxCount; count++)
    {
        vector<int> apples;
        for (int i = score.size() - 1; i >= 0; i--)
        {
            apples.push_back(score[i]);
            score.pop_back();
            if (apples.size() == m)
                break ;
        }
        minScore = *(min_element(apples.begin(), apples.end()));
        answer += minScore * m;
    }
    return answer;
}
