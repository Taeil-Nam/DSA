#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int> > lines) {
    int answer = 0;
    int min = INT32_MAX;
    int max = INT32_MIN;
    int dupFlag = 0;
    
    for (int i = 0; i < lines.size(); i++)
    {
        if (min > lines[i][0])
            min = lines[i][0];
        if (max < lines[i][1])
            max = lines[i][1];
    }
    
    answer = max - min;
    
    for (int i = min; i < max; i++)
    {
        int j = i + 1;
        dupFlag = 0;
        if (lines[0][0] <= i && lines[0][1] >= j)
            dupFlag++;
        if (lines[1][0] <= i && lines[1][1] >= j)
            dupFlag++;
        if (lines[2][0] <= i && lines[2][1] >= j)
            dupFlag++;
        if (dupFlag <= 1)
            answer--;
    }
    
    return answer;
}
