#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    getline(cin, input);
    while (input != ".") // O(n)
    {
        stack<char> st;
        bool isBreak = false;
        for (auto c : input) // O(n)
        {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')' || c == ']')
            {
                if (st.size() == 0 || (c == ')' && st.top() != '(') || (c == ']' && st.top() != '['))
                {
                    isBreak = true;
                    break;
                }
                else
                    st.pop();
            }
        }
        if (isBreak || st.size())
            cout << "no\n";
        else
            cout << "yes\n";
        getline(cin, input);
    }

    return 0;
}
/*
Time Complexity = O(n^2)
Space Complexity = O(n)

풀이
입력된 문자열의 괄호만 신경쓴다.

열린 괄호일 경우 스택에 push.
닫힌 괄호일 경우 스택의 top이 해당 괄호의 열린괄호인지 확인한다.
쌍을 이루지않으면 isBreak = true; 체크 후 break;

문자열을 전부 순회한 뒤, isBreak = true 또는 스택에 값이 남아있는 경우 no 출력.
그외의 경우 yes 출력.
*/
