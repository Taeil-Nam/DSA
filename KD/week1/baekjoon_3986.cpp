#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, ret = 0;
    cin >> N;
    string input;
    for (int i = 0; i < N; i++){
        cin >> input;
        stack<char> st;
        for (char c : input){
            if (!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);
        }
        if (st.empty())
            ret++;
    }
    cout << ret;
    return 0;
}