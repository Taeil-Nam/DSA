#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        int ret2 = 0, ret5 = 0;
        for (int j = 2; j <= num; j *= 2){
            ret2 += num / j;
        }
        for (int j = 5; j <= num; j *= 5){
            ret5 += num / j;
        }
        cout << min(ret2, ret5) << "\n";
    }
    
    return 0;
}