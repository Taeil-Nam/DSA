#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int sum = 0;
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) // O(n)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (st.empty()) continue;
            sum -= st.top();
            st.pop();
            continue;
        }
        sum += num;
        st.push(num);
    }
    cout << sum;

    return 0;
}

/*
Time Complexity = O(n)
Space Complexity = O(n)
*/