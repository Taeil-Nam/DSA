#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int table[2][7] = {};
    int N, K;
    int ans = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int s, y;
        cin >> s >> y;
        table[s][y]++;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            ans += table[i][j] / K;
            if (table[i][j] % K != 0) ans++;
        }
    }
    cout << ans;

    return 0;
}