#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    while (cin >> N){
        long long ret = 1;
        long long target = 1;
        while (target % N != 0){
            target = (target * 10 % N) + (1 % N);
            ret++;
        }
        cout << ret << "\n";
    }
    return 0;
}
// 모듈러 공식
// 1. (a+b)%c = ((a%c) + (b%c))%c
// 2. (a*b)%c = ((a%c) * (b%c))%c

// (target * 10 + 1) % N
// = ((target * 10 % N) + (1 % N)) % N