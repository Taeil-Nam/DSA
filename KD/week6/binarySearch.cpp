#include <iostream>
#include <climits>

using namespace std;

int arr[500000];
int N, M;

bool check(int val){
    int cnt = 0;
    for (int i = 0; i < M; i++){
        cnt += arr[i] / val;
        if (arr[i] % val != 0)
            cnt++;
    }
    return cnt <= N;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int left = 1;
    int right = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        cin >> arr[i];
        right = max(right, arr[i]);
    }
    int res = INT_MAX;
    while (left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            res = min(res, mid);
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << res;

    return 0;
}