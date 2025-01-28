#include <iostream>

using namespace std;

int R, C, K;
char map[10][10];
int res;
int visited[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt){
    if (cnt == K){
        if (y == 0 && x == C - 1){
            res++;
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (visited[ny][nx] || map[ny][nx] == 'T') continue;
        visited[ny][nx] = true;
        dfs(ny, nx, cnt + 1);
        visited[ny][nx] = false;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }
    visited[R - 1][0] = true;
    dfs(R - 1, 0, 1);
    cout << res;

    return 0;
}
