#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    for (int i = 1; i <= 3; i++) v.push_back(i);
    do{
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }while(next_permutation(v.begin(), v.end()));

    v.clear();
    cout << "===\n";
    for (int i = 3; i > 0; i--) v.push_back(i);
    do{
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }while(prev_permutation(v.begin(), v.end()));

    return 0;
}