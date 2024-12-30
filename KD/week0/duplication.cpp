#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v{1, 1, 2, 2, 3, 3};
    /* use map */
    // map<int, int> m;
    // for (int i : v)
    //     m[i] = 1;
    // vector<int> res;
    // for(auto it : m)
    //     cout << it.first << " ";

    /* use unique()*/
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto n : v)
        cout << n << " ";

    return 0;
}