#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input;
    while (true){
        cin >> input;
        if (input == "end") break;
        int len = input.size();
        int first = 0; int second = 1;
        bool flag = true;
        for (auto c : input){
            if (isVowel(c))
                flag = false;
        }
        if (flag == false && len >= 2){
            while (second < len){
                if (input[first] != 'e' && input[first] != 'o'
                && input[first] == input[second]){
                    flag = true;
                    break;
                }
                first++; second++;
            }
        }
        first = 0; second = 1;
        int third = 2;
        if (flag == false && len >= 3){
            while (third < len){
                if ((isVowel(input[first]) && isVowel(input[second]) && isVowel(input[third]))
                || (!isVowel(input[first]) && !isVowel(input[second]) && !isVowel(input[third]))){
                    flag = true;
                    break;
                }
                first++; second++; third++;
            }
        }
        if (flag)
            cout << "<" << input << ">" << " is not acceptable.\n";
        else
            cout << "<" << input << ">" << " is acceptable.\n";
    }

    return 0;
}