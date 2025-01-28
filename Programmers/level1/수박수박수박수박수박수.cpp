#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";
    string str1 = "수";
    string str2 = "박";
    
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            answer += str1;
        else
            answer += str2;
    }
    return answer;
}
