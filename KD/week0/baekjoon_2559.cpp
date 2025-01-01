#include <iostream>
#include <climits>

using namespace std;

int a[100005];
int psum[100005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    int ret = INT_MIN;
    for (int i = K; i <= N; i++){
        ret = max(ret, psum[i] - psum[i - K]);
    }
    cout << ret;

    return 0;
}