#include <iostream>

using namespace std;

int N, M, res;
int map[101][101];
bool isVisited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    isVisited[y][x] = true;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (isVisited[ny][nx] || map[ny][nx] == 0)
            continue;
        dfs(ny, nx);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (isVisited[i][j] || map[i][j] == 0) continue;
            dfs(i, j);
            res++;
        }
    }
    cout << res;

    return 0;
}