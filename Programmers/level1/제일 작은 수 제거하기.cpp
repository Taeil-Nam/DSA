#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int min_num = INT_MAX;
    
    if (arr.size() <= 1)
    {
        answer.push_back(-1);
        return answer;
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min_num)
            min_num = arr[i];
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != min_num)
            answer.push_back(arr[i]);
    }
    
    return answer;
}
