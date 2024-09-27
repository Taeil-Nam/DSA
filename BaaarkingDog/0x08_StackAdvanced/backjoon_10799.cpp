#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> st;
    int stickCnt = 0;
    int ans = 0;
    string input;
    cin >> input;
    for (auto c : input) // O(n)
    {
        if (c == '(')
        {
            stickCnt++;
            ans++;
        }
        else
        {
            if (st.top() == '(')
            {
                stickCnt--;
                ans--;
                ans += stickCnt;
            }
            else
                stickCnt--;
        }
        st.push(c);
    }
    cout << ans;

    return 0;
}
/*
Time Complexity = O(n)
Space Complexity = O(n)

풀이
'('가 나온 경우, stickCnt와 ans에 1을 올린다.
')'가 나온 경우
    - 레이저를 쐈다면, stickCnt와 ans에 1을 뺀 뒤, ans에 stickCnt를 더해준다.
    - 레이저가 아니라면, stickCnt에 1을 뺀다.
스택에 현재 문자를 추가한다.

스택은 st.top()을 통해 레이저 판별을 위한 자료구조일 뿐이다.
*/
