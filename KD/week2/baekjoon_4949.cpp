#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input;
    getline(cin, input);
    while (input != "."){
        stack<char> st;
        int flag = 0;
        for (auto c : input){
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')'){
                if (st.empty() || st.top() != '('){
                    flag = 1;
                    break;
                }
                if (st.top() == '(')
                    st.pop();
            }
            else if (c == ']'){
                if (st.empty() || st.top() != '['){
                    flag = 1;
                    break;
                }
                if (st.top() == '[')
                    st.pop();
            }
        }
        if (flag || !st.empty())
            cout << "no\n";
        else
            cout << "yes\n";
        getline(cin, input);
    }

    return 0;
}