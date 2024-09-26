#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<int, int> > DQ;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) // O(n)
    {
        int num;
        cin >> num;
        while (!DQ.empty() && DQ.back().second >= num) // O(1)
            DQ.pop_back();
        
        DQ.push_back({i, num});
        
        if (DQ.front().first <= i - M)
            DQ.pop_front();

        cout << DQ.front().second << " ";
    }

    return 0;
}
/*
Time Complexity = O(n)
Space Complexity = O(n)

풀이 (이 풀이를 생각해내는게 어려워서 플래티넘 같다.)
덱에 들어 있는 최근 숫자들 중, 현재 숫자보다 높은 값을 가지는 숫자는 삭제한다.
(현재 숫자가 덱의 맨 끝에 있게된다.(오름차순))

현재 숫자의 <인덱스, 숫자 값> pair를 덱에 추가한다.

덱의 맨 앞에 있는 숫자의 인덱스가 현재 숫자와의 거리를 넘는다면, 덱에서 삭제한다.

덱의 맨 앞에 있는 숫자를 출력한다.(오름차순이므로 가장 작은 값이 됨)
*/
