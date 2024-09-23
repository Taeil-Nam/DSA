#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int alpha[30] = {};
    string s1, s2;
    cin >> s1 >> s2;

    for (auto c : s1) alpha[c - 'a']++;
    for (auto c: s2) alpha[c - 'a']--;

    int ans = 0;
    for (int cnt : alpha)
        ans += abs(cnt);

    cout << ans;

    return 0;
}

/*
Time complexity = O(n)
Space comoplexity = O(30);
*/