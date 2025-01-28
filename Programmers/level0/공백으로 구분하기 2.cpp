#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    string str = "";

    for (size_t i = 0; i < my_string.length(); i++)
    {
        if (my_string[i] != ' ')
            str += my_string[i];
        else if (my_string[i] == ' '&& str.length() > 0)
        {
            answer.push_back(str);
            str = "";
            while (my_string[i + 1] == ' ')
                i++;
        }
    }
    if (str.length() > 0)
        answer.push_back(str);
    
    return answer;
}
