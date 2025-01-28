#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    for (size_t i = 0; i < num_list.size(); i++)
    {
        if (num_list[i] < 0)
            return i;
    }
    return -1;
}
