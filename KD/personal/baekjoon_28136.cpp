#include <iostream>

using namespace std;

int N, res;
int a[1000001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    a[N] = a[0];
    for (int i = 0; i < N; i++){
        if (a[i] >= a[i + 1])
            res++;
    }
    cout << res;
    
    return 0;
}