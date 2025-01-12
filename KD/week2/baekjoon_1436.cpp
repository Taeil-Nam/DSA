#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int i = 666;
    for (; ; i++){
        if (to_string(i).find("666") != string::npos) N--;
        if (N == 0) break;
    }
    cout << i;

    return 0;
}