#include <iostream>
#include <vector>

using namespace std;

int N, res, cnt;
vector<int> v;

void go(int idx, int sum){
    if (res == 10) // backtracking
        return;
    if (idx == N){
        res = max(res, sum % 11);
        cnt++;
        return;
    }
    go(idx + 1, sum + v[idx]);
    go(idx + 1, sum);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    go(0, 0);
    cout << res << " " << cnt;

    return 0;
}