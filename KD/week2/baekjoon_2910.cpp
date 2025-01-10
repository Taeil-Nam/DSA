#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> freq, order;
vector<int> v;

bool cmp(int a, int b){
    if (freq[a] == freq[b]){
        return order[a] < order[b];
    }
    return freq[a] > freq[b];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        freq[num]++;
        if (order[num] == 0)
            order[num] = i + 1;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto n : v)
        cout << n << " ";

    return 0;
}