#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp)
{
    for (size_t i = 0; i < my_string.length(); i++)
    {
        if (my_string[i] == alp[0])
            my_string[i] = toupper(my_string[i]);
    }
    
    return my_string;
}
