#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> M;
        map<string, int> m;
        string input;
        for (int j = 0; j < M; j++){
            cin >> input >> input;
            m[input]++;
        }
        int ret = 1;
        for (auto it : m){
            ret *= it.second + 1;
        }
        ret--;
        cout << ret << "\n";
    }

    return 0;
}