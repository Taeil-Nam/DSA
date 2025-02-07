#include <iostream>
#include <climits>

using namespace std;

int N, M;
int gems[300001];

bool check(int mid){
    int cnt = 0;
    for (int i = 0; i < M; i++){
        cnt += gems[i] / mid;
        if (gems[i] % mid)
            cnt++;
    }
    return cnt <= N;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int low = 1;
    int high = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        cin >> gems[i];
        high = max(high, gems[i]);
    }
    int res = INT_MAX;
    while (low <= high){
        int mid = (low + high) / 2;
        if (check(mid)){
            res = min(res, mid);
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << res;

    return 0;
}