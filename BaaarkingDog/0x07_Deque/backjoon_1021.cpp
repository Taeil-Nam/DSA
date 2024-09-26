#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int ans = 0;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dq.push_back(i);
    for (int i = 0; i < M; i++) // O(n)
    {
        int target;
        cin >> target;
        int targetIdx = find(dq.begin(), dq.end(), target) - dq.begin(); // O(n)
        while (dq.front() != target) // O(n)
        {
            if (targetIdx <= dq.size() / 2)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            else
            {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
        }
        dq.pop_front();
    }
    cout << ans;
    
    return 0;
}
/*
Time Complexity = O(n^2)
Space Complexity = O(n)

풀이
뽑을 숫자의 인덱스가 덱 중간보다 작거나 같으면 왼쪽으로 이동하고,
반대의 경우 오른쪽으로 이동하는 것이 가장 적은 이동라는 것이 핵심.

추가로, 22번 줄에서 iterator를 활용하여 인덱스를 찾아내는 기법도 익혀두자.
*/