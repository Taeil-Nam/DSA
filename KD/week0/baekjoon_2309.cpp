#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int a[9];

void combi(int start, vector<int>& v){
    if (v.size() == 7){
        if (accumulate(v.begin(), v.end(), 0) == 100){
            for (auto n : v) cout << n << "\n";
            exit(0);
        }
    }
    for (int i = start + 1; i < 9; i++){
        v.push_back(a[i]);
        combi(i, v);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 9; i++){
        cin >> a[i];
    }
    sort(a, a + 9);
    vector<int> v;
    combi(-1, v);
   
    return 0;
}