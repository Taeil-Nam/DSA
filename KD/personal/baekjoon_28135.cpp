#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cnt = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        string num = to_string(i);
        if (num.find("50") != string::npos){
            cnt += 2;
        }
        else
            cnt++;
    }
    cout << cnt;
    
    return 0;
}