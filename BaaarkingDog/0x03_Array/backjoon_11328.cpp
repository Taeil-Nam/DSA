#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int alpha[30] = {};
        string s1, s2;
        cin >> s1 >> s2;
        for (auto c : s1) alpha[c - 'a']++;
        for (auto c : s2) alpha[c - 'a']--;

        bool isPossible = true;
        for (int val : alpha)
            if (val != 0) isPossible = false;
        
        if (isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }

    return 0;
}