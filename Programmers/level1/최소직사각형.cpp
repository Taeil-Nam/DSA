#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int MaxW = 0;
    int MaxH = 0;
    
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
            swap(sizes[i][0], sizes[i][1]);
    }
    
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] > MaxW)
            MaxW = sizes[i][0];
        if (sizes[i][1] > MaxH)
            MaxH = sizes[i][1];
    }
    
    return MaxW * MaxH;
}

/*
- w < h 인 경우, w와 h를 swap.
수정 전)
60 50
30 70
60 30
80 40

----
수정 후)
60 50
70 30
60 30
80 40
*/
