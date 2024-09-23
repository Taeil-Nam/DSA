#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        list<char> lst;
        auto cursor = lst.begin();
        string s;
        cin >> s;
        for (auto c : s) // O(n)
        {
            if (c == '<')
            {
                if (cursor != lst.begin()) cursor--;
            }
            else if (c == '>')
            {
                if (cursor != lst.end()) cursor++;
            }
            else if (c == '-')
            {
                if (cursor != lst.begin())
                {
                    cursor--;
                    cursor = lst.erase(cursor); // O(1)
                }
            }
            else
            {
                lst.insert(cursor, c); // O(1)
            }
        }
        for (auto val : lst)
            cout << val;
        cout << '\n';
    }
    
    return 0;
}

/*
Time Complexity = O(n)
Space Complexity = O(n)
*/
