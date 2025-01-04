#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, ret;

void combi(int start, vector<int>& b, int a[]){
    if (b.size() == 2){
        if (b[0] + b[1] == M)
            ret++;
        return;
    }
    for (int i = start + 1; i < N; i++){
        b.push_back(a[i]);
        combi(i, b, a);
        b.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int a[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector<int> b;
    combi(-1, b, a);
    cout << ret;
    return 0;
}