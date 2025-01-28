#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n)
{
    string answer = &my_string[my_string.size() - n];
    
    return answer;
}
