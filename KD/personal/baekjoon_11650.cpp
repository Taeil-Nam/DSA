#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& l , pair<int, int>& r){
    if (l.first == r.first)
        return l.second < r.second;
    return l.first < r.first;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<pair<int, int>> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto pos : v){
        cout << pos.first << " " << pos.second << "\n";
    }
    return 0;
}