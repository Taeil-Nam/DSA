#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string input;
        int param;
        cin >> input;
        if (input == "push")
        {
            cin >> param;
            st.push(param);
        }
        else if (input == "pop")
        {
            if (st.empty()) cout << "-1\n";
            else
            {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (input == "size") cout << st.size() << "\n";
        else if (input == "empty") cout << st.empty() << "\n";
        else if (input == "top")
        {
            if (st.empty()) cout << "-1\n";
            else cout << st.top() << "\n";
        }
    }

    return 0;
}

/*
Time Complexity = O(n)
Space Complexity = O(n)
*/