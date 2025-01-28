#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int solution(string s) {
    const char* str = s.c_str(); // c_str() = string을 c스타일 문자열로 변경.
    int answer = atoi(str);
    
    return answer;
}