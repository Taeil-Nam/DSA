#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    vector<bool> flag(10);
    int oldNum = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (oldNum != arr[i])
            flag.assign(10, 0);
        for (int n = 0; n < 10; n++)
        {
            if (arr[i] == n && flag[n] == false)
            {
                answer.push_back(n);
                flag[n] = true;
                oldNum = n;
                break;
            }
        }
    }
    
    return answer;
}
