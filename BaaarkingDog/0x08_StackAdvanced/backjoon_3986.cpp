#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) // O(n)
    {
        stack<char> st;
        string word;
        cin >> word;
        for (auto c : word) // O(n)
        {
            if (st.size() == 0) st.push(c);
            else if (st.top() != c) st.push(c);
            else st.pop();
        }
        if (st.size() == 0) ans++;
    }
    cout << ans;

    return 0;
}
/*
Time Complexity = O(n^2)
Space Complexity = O(n)

풀이
문자 쌍을 찾는 문제라는 것과, 스택을 사용하면 된다는 것을 알면 쉬움.
*/
