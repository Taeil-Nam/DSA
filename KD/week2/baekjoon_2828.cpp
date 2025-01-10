#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, J;
    cin >> N >> M >> J;
    int left = 1;
    int right = left + M - 1;
    int cnt = 0;
    for (int i = 0; i < J; i++){
        int pos;
        cin >> pos;
        if (left <= pos && pos <= right){
            continue;
        }
        else if (pos < left){
            int sub = left - pos;
            left -= sub;
            right -= sub;
            cnt += sub;
        }
        else if (pos > right){
            int sub = pos - right;
            left += sub;
            right += sub;
            cnt += sub;
        }
    }
    cout << cnt;

    return 0;
}