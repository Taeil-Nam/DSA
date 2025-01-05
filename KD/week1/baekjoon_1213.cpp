#include <iostream>
#include <string>

using namespace std;

int cnt[200];
string input, ret;
char mid;
int flag;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> input;
    for (char c : input) cnt[c]++;
    for (char c = 'Z'; c >= 'A'; c--){
        if (cnt[c]){
            if (cnt[c] & 1){
                mid = c;
                flag++;
                if (flag >= 2) break;
                cnt[c]--;
            }
            for (int i = 0; i < cnt[c] / 2; i++){
                ret = c + ret;
                ret = ret + c;
            }
        }
    }
    if (mid)
        ret.insert(ret.begin() + ret.size() / 2, mid);
    if (flag >= 2)
        cout << "I'm Sorry Hansoo";
    else
        cout << ret;
    
    return 0;
}