#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    size_t end = 0;
    
    while (my_string.find(' ') != string::npos)
    {
        end = my_string.find(' ');
        answer.push_back(my_string.substr(0, end));
        my_string.erase(0, end + 1);
    }
    answer.push_back(my_string.substr(0, my_string.length()));
    
    return answer;
}
