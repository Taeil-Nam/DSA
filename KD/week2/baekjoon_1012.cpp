#include <iostream>
#include <cstring>

using namespace std;

int T, M, N, K;
int map[51][51];
int visited[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (visited[ny][nx] || map[ny][nx] == 0)
            continue;
        dfs(ny,nx);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> M >> N >> K;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        for (int j = 0; j < K; j++){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        int res = 0;
        for (int y = 0; y < N; y++){
            for (int x = 0; x < M; x++){
                if (visited[y][x] || map[y][x] == 0)
                    continue;
                dfs(y, x);
                res++;
            }
        }
        cout << res << '\n';
    }

    return 0;
}