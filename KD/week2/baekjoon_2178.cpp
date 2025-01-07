#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
int map[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[101][101];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        string input;
        cin >> input;
        for (int j = 0; j < M; j++){
            map[i][j] = input[j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (true){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == N - 1 && x == M - 1)
            break;
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (visited[ny][nx] || map[ny][nx] == '0')
                continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    cout << visited[N - 1][M - 1] - visited[0][0] + 1;

    return 0;
}