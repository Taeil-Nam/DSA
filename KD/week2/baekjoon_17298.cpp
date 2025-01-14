#include <iostream>
#include <stack>

using namespace std;

int N;
int a[1000001], res[1000001];
stack<int> st;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    fill(&res[0], &res[0] + 1000001, -1);
    for (int i = 0; i < N; i++){
        cin >> a[i];
        while (st.size() && a[st.top()] < a[i]){
            res[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < N; i++){
        cout << res[i] << " ";
    }
    
    return 0;
}