#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    string pattern;
    cin >> N;
    cin >> pattern;
    int pos = pattern.find('*');
    string prefix = pattern.substr(0, pos);
    string suffix = pattern.substr(pos + 1);
    string input;
    for (int i = 0; i < N; i++){
        cin >> input;
        if (prefix.size() + suffix.size() > input.size()){
            cout << "NE\n";
            continue;
        }
        if (prefix == input.substr(0, prefix.size())
        && suffix == input.substr(input.size() - suffix.size()))
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}