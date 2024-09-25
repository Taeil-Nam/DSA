#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    string ans;
    int cnt = 1;
    int N;
    cin >> N;
    while (N--) // O(n)
    {
        int num;
        cin >> num;
        while (cnt <= num) // O(n)
        {
            st.push(cnt++);
            ans += "+\n";
        }
        if (st.top() != num)
        {
            cout << "NO";
            return 0;
        }
        st.pop();
        ans += "-\n";
    }
    cout << ans;

    return 0;
}

/*
Time Complexity = O(n)
중첩 while 이지만, while (cnt <= num)은 잔체적으로 봤을 때, N 만큼만 불린다.
즉, 첫 번째 while 루프가 돌 때마다, while (cnt <= num)이 계속 수행되는게 아니다.

Space Complexity = O(n)
*/