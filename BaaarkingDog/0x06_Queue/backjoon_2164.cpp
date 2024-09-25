#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) // O(n)
        Q.push(i);
    while (Q.size() > 1) // O(n)
    {
        Q.pop(); // O(1)
        Q.push(Q.front()); // O(1)
        Q.pop(); // O(1)
    }
    cout << Q.front();

    return 0;
}

/*
Time Complexity = O(n)
Space Complexity = O(n)
*/