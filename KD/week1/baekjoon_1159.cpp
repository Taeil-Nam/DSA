#include <iostream>
#include <string>

using namespace std;

int alpha[26];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        string firstName;
        cin >> firstName;
        alpha[firstName[0] - 'a']++;
    }
    bool flag = false;
    for (int i = 0; i < 26; i++){
        if (alpha[i] >= 5){
            cout << (char)('a' + i);
            flag = true;
        }
    }
    if (flag == false) cout << "PREDAJA";

    return 0;
}