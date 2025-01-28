#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    char c;

    for (size_t i = 0; i < s.length(); i++)
    {
        c = s[i];
        if (st.empty() == true)
            st.push(c);
        else
        {
            if (st.top() == '(' && c == ')')
                st.pop();
            else
                st.push(c);
        }
    }
    
    if (st.empty() == true)
        return true;
    else
        return false;
}
