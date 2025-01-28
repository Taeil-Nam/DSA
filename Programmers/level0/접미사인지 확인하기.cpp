#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix)
{
    size_t suffixIndex = my_string.rfind(is_suffix);
    
    if (suffixIndex != string::npos)
    {
        if (my_string[suffixIndex + is_suffix.size()] == '\0')
            return true;
    }
    return false;
}
