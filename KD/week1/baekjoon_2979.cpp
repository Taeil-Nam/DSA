#include <iostream>

using namespace std;

int a[101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int sum = 0;
    int A, B, C;
    cin >> A >> B >> C;
    for (int i = 0; i < 3; i++){
        int start, end;
        cin >> start >> end;
        for (int t = start; t < end; t++){
            a[t]++;
        }
    }
    for (int t = 1; t <= 100; t++){
        if (a[t] == 1) sum += A;
        else if (a[t] == 2) sum += B * 2;
        else if (a[t] == 3) sum += C * 3;
    }
    cout << sum;
    return 0;
}