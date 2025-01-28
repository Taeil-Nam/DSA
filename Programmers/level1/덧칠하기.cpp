#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    int wallSize = n;
    vector<bool> wall(wallSize, false);
    
    for (int i = 0; i < section.size(); i++)
        wall[section[i] - 1] = true;
    
    for (int i = 0; i < wallSize; i++)
    {
        if (wall[i] == true)
        {
            for (int j = i; j < i + m; j++)
            {
                if (j >=  wallSize)
                    break;
                wall[j] = false;
            }
            answer++;
        }
    }
    
    return answer;
}
