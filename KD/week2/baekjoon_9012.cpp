#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        stack<char> st;
        string input;
        int flag = 0;
        cin >> input;
        for (int j = 0; j < input.size(); j++){
            if (input[j] == '(')
                st.push(input[j]);
            else if (input[j] == ')'){
                if (st.empty()){
                    cout << "NO\n";
                    flag = 1;
                    break;
                }
                else
                    st.pop();
            }
        }
        if (flag)
            continue;
        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}