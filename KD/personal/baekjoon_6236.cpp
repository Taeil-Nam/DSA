#include <iostream>

using namespace std;

int N, M;
int money[100001];

bool check(int mid){
    int temp = mid;
    int cnt = 1;
    for (int i = 0; i < N; i++){
        if (money[i] <= mid){
            mid -= money[i];
        }
        else{
            mid = temp;
            cnt++;
            if (money[i] > mid)
                return false;
            else
                mid -= money[i];
        }
    }
    return cnt <= M;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int low = 1;
    int high = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> money[i];
        high += money[i];
    }
    int res = 0;
    while (low <= high){
        int mid = (low + high) / 2;
        if (check(mid)){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << res;

    return 0;
}