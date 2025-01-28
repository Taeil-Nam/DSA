#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";
    string temp = "";
    vector<int> nums;
    
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            nums.push_back(stoi(temp));
            temp = "";
        }
        else
            temp.push_back(s[i]);
    }
    
    nums.push_back(stoi(temp));
    sort(nums.begin(), nums.end());
    
    answer = to_string(nums[0]) + " " + to_string(nums[nums.size() - 1]);
    
    return answer;
}
