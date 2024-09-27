#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> st;
    int ans = 0;
    int mul = 1;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        char c = input[i];
        if (c == '(')
        {
            mul *= 2;
            st.push(c);
        }
        else if (c == '[')
        {
            mul *= 3;
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                cout << "0";
                return 0;
            }
            if (input[i - 1] == '(')
                ans += mul;
            mul /= 2;
            st.pop();
        }
        else if (c == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                cout << "0";
                return 0;
            }
            if (input[i - 1] == '[')
                ans += mul;
            st.pop();
            mul /= 3;
        }
    }

    if (st.empty())
        cout << ans;
    else
        cout << 0;

    return 0;
}
/*
Time Complexity = O(n)
Space Complexity = O(n)

풀이
(()[[]]) = 2(2 + 3x3) = 2x2 + 2x3x3과 같다는 것을 알아야함.
'('가 나왔을 때 mul을 2배, '['가 나왔을 때 3배를 늘려준다.
닫는 괄호가 나왔을 때, 바로 이전 문자가 짝이 맞는 여는 괄호인 경우, 현재 mul을 ans에 더한다.
')'이면 mul을 2로 나눠주고, ']'이면 3으로 나눠준다.

스택은 괄호 쌍이 맞는지 확인을 위해 사용된다.
*/
