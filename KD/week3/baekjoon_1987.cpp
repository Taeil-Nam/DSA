#include <iostream>
#include <string>

using namespace std;

int R, C;
char map[21][21];
int alpha[128];
int cnt, res;
int dy[] = {-1, 0, 1 ,0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    cnt++;
    alpha[map[y][x]] = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (alpha[map[ny][nx]]) continue;
        dfs(ny, nx);
    }
    res = max(res, cnt);
    cnt--;
    alpha[map[y][x]] = 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        string input;
        cin >> input;
        for (int j = 0; j < C; j++){
            map[i][j] = input[j];
        }
    }
    dfs(0, 0);
    cout << res;

    return 0;
}