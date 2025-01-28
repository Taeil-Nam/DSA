#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    string answer = myString;
    
    for (size_t i = 0; i < answer.size(); i++)
        answer[i] = tolower(answer[i]);

    return answer;
}
