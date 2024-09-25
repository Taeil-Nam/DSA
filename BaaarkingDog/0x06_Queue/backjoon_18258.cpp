#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        if (input == "push")
        {
            int num;
            cin >> num;
            Q.push(num);
        }
        else if (input == "pop")
        {
            if (Q.empty())
                cout << "-1\n";
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (input == "size")
        {
            cout << Q.size() << "\n";
        }
        else if (input == "empty")
        {
            cout << Q.empty() << "\n";
        }
        else if (input == "front")
        {
            if (Q.empty())
                cout << "-1\n";
            else
                cout << Q.front() << "\n";
        }
        else if (input == "back")
        {
            if (Q.empty())
                cout << "-1\n";
            else
                cout << Q.back() << "\n";
        }
    }

    return 0;
}
