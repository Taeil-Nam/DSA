#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    int count = 0;
    
    if (s.size() != 4 && s.size() != 6)
        return false;
    
    while (s[count])
    {
        if ('0' <= s[count] && s[count] <= '9')
        {
            count++;
            continue;
        }
        else
            break;
    }
    
    if (count == s.size())
        return true;
    else
        return false;
}
