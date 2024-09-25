#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int> > tower;
    int N;
    cin >> N;
    tower.push({100000001, 0});
    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;
        while (tower.top().first < height)
            tower.pop();
        cout << tower.top().second << " ";
        tower.push({height, i});
    }

    return 0;
}

/*
Time Complexity = O(n)
while문에서 각 타워는 전체적으로 단 한번만 push or pop 되므로,
전체 시간 복잡도 = O(n)

Space Complexity = O(n)
*/