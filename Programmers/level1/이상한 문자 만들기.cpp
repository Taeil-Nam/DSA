#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    int count = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            count = 0;
            continue;
        }
        if (count % 2 == 0 && 'a' <= s[i] && s[i] <= 'z')
            s[i] -= 32;
        else if (count % 2 == 1 && 'A' <= s[i] && s[i] <= 'Z')
            s[i] += 32;
        count++;
    }
    
    return s;
}
