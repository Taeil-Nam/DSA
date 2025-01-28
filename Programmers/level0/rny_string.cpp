#include <string>
#include <vector>

using namespace std;

string solution(string rny_string)
{
    string answer = rny_string;
    
    while (answer.find("m") != string::npos)
    {
        answer.replace(answer.find("m"), 1, "rn");
    }
    
    return answer;
}
