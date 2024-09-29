#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[500][500];
bool visit[500][500];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int pictureCnt = 0;
    int maxWidth = 0;
    queue<pair<int, int> > Q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int N, M;
    cin >> N >> M;
    for (int row = 0; row < N; row++) // O(n)
        for (int col = 0; col < M; col++) // O(n)
            cin >> board[row][col];
    for(int row = 0; row < N; row++) // O(n)
    {
        for (int col = 0; col < M; col++) // O(n)
        {
            if (visit[row][col] || board[row][col] == 0) continue;
            visit[row][col] = true;
            Q.push(make_pair(row, col));
            pictureCnt++;
            int width = 1;
            while (!Q.empty())// O(n)
            {
                pair<int, int> current = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = current.first + dy[dir];
                    int nx = current.second + dx[dir];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (visit[ny][nx] || board[ny][nx] == 0) continue;
                    visit[ny][nx] = true;
                    Q.push(make_pair(ny, nx));
                    width++;
                }
            }
            maxWidth = ::max(width, maxWidth);
        }
    }
    cout << pictureCnt << "\n";
    cout << maxWidth;

    return 0;
}
/*
Time Complexity = O(n)
중첩된 루프가 있지만, visit에 의해 방문한 곳은 다시 방문하지 않으므로, 전체적으로 O(n)
Space Complexity = O(n)

풀이
BFS 기본 로직을 중첩 for문으로 묶는다.
방문하지 않는 위치를 시작 위치로 정하고, BFS를 수행한다.

BFS 로직을 수행할 때마다 pictureCnt를 1 올린다.
BFS 로직 내부에서, 다음 위치로 이동할 때마다 width를 올린다.

BFS를 마치면, maxWidth를 갱신한다.
*/