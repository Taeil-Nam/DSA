#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    int NewC;

    for (int i = 0; i < s.size(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            NewC = s[i] + n;
            if (NewC > 'z')
                NewC = NewC % 'z' + 'a' - 1;
            s[i] = NewC;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            NewC = s[i] + n;
            if (NewC > 'Z')
                NewC = NewC % 'Z' + 'A' - 1;
            s[i] = NewC;
        }
    }
    
    return s;
}
