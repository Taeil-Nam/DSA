#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < arr[i]; j++)
            answer.push_back(arr[i]);
    }
    
    return answer;
}
