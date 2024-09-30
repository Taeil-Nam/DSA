#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

string board[100];
int dist[100][100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > Q;
    int dx[4] = { 1, 0, -1, 0};
    int dy[4] = { 0, 1, 0, -1};
    int count = 0;
    int N, M;
    cin >> N >> M;
    for (int row = 0; row < N; row++) // O(n)
        cin >> board[row];
    dist[0][0] = 1;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) // O(n)
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) // O(1)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (dist[ny][nx] || board[ny][nx] != '1') continue;
            dist[ny][nx] = dist[cur.first][cur.second] + 1;
            Q.push(make_pair(ny, nx));
        }
    }
    cout << dist[N - 1][M - 1];

    return 0;
}
/*
Time Complexity = O(n)
Space Complexity = O(n)

풀이
기존 BFS에서, 방문했는지를 기록하는 배열 visit을 dist로 변경하여 거리를 기록하도록 한다.

주의
borad가 int형 배열이 아닌 string 이므로, 조건문에서 != '1' 이라고 해주어야한다.
*/