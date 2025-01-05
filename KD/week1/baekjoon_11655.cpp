#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++){
        if (isalpha(input[i])){
            if (('A' + 13 <= input[i] && input[i] <= 'Z')
                || ('a' + 13 <= input[i] && input[i] <= 'z'))
                input[i] -= 13;
            else
                input[i] += 13;
        }
    }
    cout << input;

    return 0;
}