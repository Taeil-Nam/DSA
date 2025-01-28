#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "";
    int cards1_i = 0;
    int cards2_i = 0;
    
    for (int i = 0; i < goal.size(); i++)
    {
        if (cards1[cards1_i] == goal[i])
            cards1_i++;
        else if (cards2[cards2_i] == goal[i])
            cards2_i++;
        else if (cards1_i == cards1.size() ||  cards2_i == cards2.size())
            return answer = "No";
        else
            return answer = "No";
    }
    
    return answer = "Yes";
}
