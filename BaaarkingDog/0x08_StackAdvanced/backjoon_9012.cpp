#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) // O(n)
    {
        stack<int> st;
        bool isBreak = false;
        string input;
        cin >> input;
        for (char c : input) // O(n)
        {
            if (c == '(') st.push(c);
            else
            {
                if (st.size() == 0)
                {
                    isBreak = true;
                    break;
                }
                else if (st.top() == '(')
                    st.pop();
            }
        }
        if (st.size() || isBreak)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
/*
Time Complexity = O(n^2)
Space Complexity = O(n)

풀이
괄호 쌍 찾기. 스택 사용.
*/
