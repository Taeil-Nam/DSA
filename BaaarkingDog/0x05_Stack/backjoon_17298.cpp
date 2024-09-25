#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int nums[1000001];
int ans[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) // O(n)
        cin >> nums[i];
    for (int i = N - 1; i >= 0; i--) // O(n)
    {
        while (!st.empty() && st.top() <= nums[i]) // O(1) : 프로그램 전체에서 N번.
            st.pop();
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(nums[i]);
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";

    return 0;
}
/*
Time Complexity = O(n)
Space Complexity = O(n)

풀이
입력 값을 배열에 저장해두고, 맨 뒤의 숫자부터 스택에 넣으면서
현재 값보다 작거나 같은 값들을 스택에서 제거한다.
만약, 스택에 남은게 없으면 -1, 있으면 스택의 top을 ans에 저장한다.
ans에도 동일하게 맨 마지막부터 결과가 저장된다.
*/