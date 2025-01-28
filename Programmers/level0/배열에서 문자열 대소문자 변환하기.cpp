#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    for (size_t i = 0; i < strArr.size(); i++)
    {
        for (size_t j = 0; j < strArr[i].length(); j++)
        {
            if (i % 2 == 1)
                strArr[i][j] = toupper(strArr[i][j]);
            else
                strArr[i][j] = tolower(strArr[i][j]);
        }
    }
    
    return strArr;
}
