#include <iostream>

using namespace std;

int alpha[26];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input;
    getline(cin, input);
    for (char c : input){
        alpha[c - 'a']++;
    }
    for (int n : alpha) cout << n << " ";

    return 0;
}