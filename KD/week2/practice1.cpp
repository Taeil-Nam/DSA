#include <iostream>

using namespace std;

int map[3][3];
bool isVisited[3][3];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(int y, int x){
    isVisited[y][x] = true;
    cout << y << ", " << x << '\n';
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
            continue;
        if (isVisited[ny][nx] || map[ny][nx] == 0)
            continue;
        go(ny, nx);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> map[i][j];
        }
    }
    go(0, 0);
    return 0;
}