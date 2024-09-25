#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    long long ans = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) // O(n)
    {
        int height;
        cin >> height;
        while (!st.empty() && st.top() <= height) // O(n) : 프로그램 전체에서 n번.
            st.pop();
        ans += st.size();
        st.push(height);
    }
    cout << ans;

    return 0;
}
/*
Time Complexity = O(n)
Space Complexity = O(n)

풀이
각 건물이 볼 수 있는 건물들의 합을 구한다는 것은,
각 건물들이 보여질 수 있는 건물들의 합을 구한다는 것과 동일하다.

현재 입력된 건물보다 높지 않은 건물들은 스택에서 삭제 한 뒤,
남아있는 건물들(스택의 크기)을 결과에 더한다.
그 후, 현재 건물을 스택에 넣는다.
*/