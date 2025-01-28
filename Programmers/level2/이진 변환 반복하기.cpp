#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    int convertCount = 0;
    int eraseCount = 0;
    size_t strLength = 0;
    
    while (s.length() > 1)
    {
        // 1. '0' 제거
        while (s.find('0') != string::npos)
        {
            s.erase(s.find('0'), 1);
            eraseCount++;
        }
        
        // 2. s에 s의 길이를 2진법으로 표현하여 저장
        strLength = s.length();
        s = "";
        while (strLength != 0)
        {
            s += strLength % 2 + '0';
            strLength /= 2;
        }
        reverse(s.begin(), s.end());
        convertCount++;
    }
    
    answer.push_back(convertCount);
    answer.push_back(eraseCount);
    
    return answer;
}
