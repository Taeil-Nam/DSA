#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    string bomb;
    string res;
    stack<char> st;
    cin >> str >> bomb;
    for (int i = 0; i < str.size(); i++){
        char c = str[i];
        st.push(c);
        if (st.size() < bomb.size()) continue;
        if (c == bomb.back()){
            string temp;
            for (int j = 0; j < bomb.size(); j++){
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            if (temp == bomb) continue;
            else{
                for (int j = 0; j < temp.size(); j++){
                    st.push(temp[j]);
                }
            }
        }
    }
    if (st.empty()){
        cout << "FRULA";
    }
    else{
        while (st.size()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        cout << res;
    }
    
    
    return 0;
}