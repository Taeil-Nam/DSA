#include <iostream>

using namespace std;

int a[100001], psum[100001], N, M, A, B;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    for (int i = 0; i < M; i++){
        cin >> A >> B;
        cout << psum[B] - psum[A - 1] << '\n';
    }

    return 0;
}