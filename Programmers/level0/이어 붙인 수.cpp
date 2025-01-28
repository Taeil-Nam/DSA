#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int answer = 0;
    int oddSum = 0;
    int evenSum = 0;
    
    for (size_t i = 0; i < num_list.size(); i++)
    {
        if (num_list[i] % 2 == 0)
            evenSum = evenSum * 10 + num_list[i];
        else
            oddSum = oddSum * 10 + num_list[i];
    }
    
    answer = oddSum + evenSum;
    
    return answer;
}
