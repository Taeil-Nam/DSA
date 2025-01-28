#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = s;
    
    for (int i = 0; i < answer.length(); i++)
        answer[i] = tolower(answer[i]);

    for (int i = 0; i < answer.length(); i++)
    {
        if (i == 0)
            answer[i] = toupper(answer[i]);
        if (answer[i] == ' ')
            answer[i + 1] = toupper(answer[i + 1]);
    }
    
    return answer;
}
