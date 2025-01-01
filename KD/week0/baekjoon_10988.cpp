#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input, input_r;
    cin >> input;
    input_r = input;
    reverse(input_r.begin(), input_r.end());
    if (input == input_r) cout << 1;
    else cout << 0;

    return 0;
}