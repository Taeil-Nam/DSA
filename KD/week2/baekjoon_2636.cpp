#include <iostream>

using namespace std;

int N, M, hours, cheeses, flag;
int map[101][101];
int visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (visited[ny][nx]) continue;
        if (map[ny][nx] == 1){
            map[ny][nx] = 0;
            visited[ny][nx] = 1;
            continue;
        }
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
    while (true){
        flag = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (map[i][j] == 1)
                    flag = 1;
            }
        }
        if (flag == 0)
            break;
        cheeses = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (map[i][j] == 1)
                    cheeses++;
            }
        }
        fill(&visited[0][0], &visited[0][0] + (101 * 101), 0);
        dfs(0, 0);
        hours++;
    }
    cout << hours << "\n" << cheeses;

    return 0;
}