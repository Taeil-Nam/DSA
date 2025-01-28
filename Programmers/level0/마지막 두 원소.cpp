#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    int last = num_list[num_list.size() - 1];
    int beforeLast = num_list[num_list.size() - 2];

    if (last > beforeLast)
        num_list.push_back(last - beforeLast);
    else
        num_list.push_back(2 * last);
    
    return num_list;
}
