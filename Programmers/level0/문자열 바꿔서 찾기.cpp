#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    for (size_t i = 0; i < myString.length(); i++)
    {
        if (myString[i] == 'A')
            myString[i] = 'B';
        else if (myString[i] == 'B')
            myString[i] = 'A';
    }
    
    if (myString.find(pat) != string::npos)
        return true;
    else
        return false;
}
