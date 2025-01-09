#include <iostream>
#include <cstring>

using namespace std;

int N, maxHeight, rain, res;
int map[101][101];
int visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = true;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (visited[ny][nx] || map[ny][nx] - rain <= 0)
            continue;
        dfs(ny, nx);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
            maxHeight = max(maxHeight, map[i][j]);
        }
    }
    for (rain = 0; rain <= maxHeight; rain++){
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int y = 0; y < N; y++){
            for (int x = 0; x < N; x++){
                if (visited[y][x] || map[y][x] - rain <= 0)
                    continue;
                dfs(y, x);
                cnt++;
            }
        }
        res = max(res, cnt);
    }
    cout << res;

    return 0;
}