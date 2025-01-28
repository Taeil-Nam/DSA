#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(int n)
{
    stringstream ss;
    string answer = "";
    
    ss << n;
    ss >> answer;
    
    return answer;
}
