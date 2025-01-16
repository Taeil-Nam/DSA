#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

bool isPrime(int num){
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0)
            return false;
    }
    return true;
}

int go(int idx, int sum){
    if (idx == N){
        return isPrime(sum);
    }
    return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    cout << go(0, 0);

    return 0;
}