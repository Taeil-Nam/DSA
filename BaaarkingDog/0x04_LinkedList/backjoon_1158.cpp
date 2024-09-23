#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    
    list<int> lst;
    int ans[N];
    int idx = 0;

    for (int i = 1; i <= N; i++) // O(n)
        lst.push_back(i); // O(1)

    auto it = lst.begin();
    while (!lst.empty()) // O(n)
    {
        for (int i = 0; i < K - 1; i++) // O(n)
        {
            it++;
            if (it == lst.end())
                it = lst.begin();
        }
        ans[idx++] = *it;
        it = lst.erase(it);
        if (it == lst.end())
            it = lst.begin();
    }

    cout << "<";
    for (int i = 0; i < N; i++)
    {
        cout << ans[i];
        if (i != N - 1)
            cout << ", ";
    }
    cout << ">";

    return 0;
}

/*
Time Complexity = O(n^2)
Space Complexity = O(n)
*/
