#include <iostream>

using namespace std;

int nums[1000001];
int seen[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (x - nums[i] > 0 && seen[x - nums[i]])
            ans++;
        seen[nums[i]] = true;
    }

    cout << ans;

    return 0;
}

/*
Time Complexity = O(n)
Space Complexity = O(2000000)
*/