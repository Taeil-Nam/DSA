#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int sum = 0;
    int multi = 1;
    
    for (size_t i = 0; i < num_list.size(); i++)
    {
        sum += num_list[i];
        multi *= num_list[i];
    }
    
    if (multi < sum * sum)
        return true;
    else
        return false;
}
