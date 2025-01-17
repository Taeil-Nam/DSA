#include <iostream>

using namespace std;

bool isLargePrime(long long num){
    if (num <= 1) return false;
    if (num == 2) return false;
    for (int i = 2; i <= 1000000; i++){
        if (num % i == 0)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        long long num;
        cin >> num;
        if (isLargePrime(num))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}