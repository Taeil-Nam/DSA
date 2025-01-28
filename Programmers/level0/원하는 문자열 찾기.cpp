#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    for (size_t i = 0; i < myString.length(); i++)
        myString[i] = tolower(myString[i]);
    for (size_t i = 0; i < pat.length(); i++)
        pat[i] = tolower(pat[i]);

    if (myString.find(pat) != string::npos)
        return true;
    else
        return false;
}
