#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string str1 = "김서방은 ";
    string str2;
    string str3 = "에 있다";
    int index = 0;
    
    for (; index < seoul.size(); index++)
    {
        if (seoul[index] == "Kim")
            break ;
    }
    str2 = to_string(index);
    
    return str1 + str2 + str3;
}
