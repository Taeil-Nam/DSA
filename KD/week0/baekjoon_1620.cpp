#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    unordered_map<int, string> nm;
    unordered_map<string, int> sm;
    for (int i = 1; i <= N; i++){
        string name;
        cin >> name;
        nm[i] = name;
        sm[name] = i;
    }
    for (int i = 0; i < M; i++){
        string input;
        cin >> input;
        if (isdigit(input[0])){
            cout << nm[atoi(input.c_str())] << "\n";
        }
        else
            cout << sm[input] << "\n";
    }

    return 0;
}