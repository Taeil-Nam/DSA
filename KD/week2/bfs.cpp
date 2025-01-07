#include <iostream>
#include <queue>

using namespace std;

int N, M, res;
int start_x, start_y, end_x, end_y;
int end[1][1];
int map[101][101];
int visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(){
    cin >> N >> M;
    cin >> start_y >> start_x;
    cin >> end_y >> end_x;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    queue<pair<int, int>> q;
    visited[start_y][start_x] = 1;
    q.push({start_y, start_x});
    while (true){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == end_y && x == end_x)
            break;
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (visited[ny][nx] || map[ny][nx] == 0)
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    res = visited[end_y][end_x] - visited[start_y][start_x] + 1;
    cout << res;

    return 0;
}