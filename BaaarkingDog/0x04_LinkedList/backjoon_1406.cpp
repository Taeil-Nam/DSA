#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> lst;
    list<char>::iterator cursor;
    string s;
    int M;
    cin >> s;
    cin >> M;

    for (char c : s) // O(n)
        lst.push_back(c);
    cursor = lst.end();
    for (int i = 0; i < M; i++)
    {
        char order, param = 0;
        cin >> order;
        if (order == 'P')
        {
            cin >> param;
            lst.insert(cursor, param); // O(1)
        }
        if (order == 'L' && cursor != lst.begin()) cursor--;
        if (order == 'D' && cursor != lst.end()) cursor++;
        if (order == 'B' && cursor != lst.begin())
        {
            cursor--;
            cursor = lst.erase(cursor); // O(1)
        }
    }

    for (auto val : lst) // O(n)
        cout << val;

    return 0;
}

/*
Time Complexity = O(n)
Space Complexity = O(n)
*/
