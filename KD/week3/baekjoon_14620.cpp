#include <iostream>

using namespace std;

int N;
int map[15][15];
int visited[15][15];
int res = 1000000;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool canBloomed(int y, int x){
    if (visited[y][x]) return false;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) return false;
        if (visited[ny][nx]) return false;
    }
    return true;
}

void bloom(int y, int x){
    visited[y][x] = true;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = true;
    }
}

int calCost(int y, int x){
    int sum = 0;
    sum += map[y][x];
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        sum += map[ny][nx];
    }
    return sum;
}

void fallen(int y, int x){
    visited[y][x] = false;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = false;
    }
}

void go(int cnt, int sumCost){
    if (cnt == 3){
        res = min(res, sumCost);
        return;
    }
    for (int y = 0; y < N; y++){
        for (int x = 0; x < N; x++){
            if (canBloomed(y, x)){
                bloom(y, x);
                go(cnt + 1, sumCost + calCost(y, x));
                fallen(y, x);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    go(0, 0);
    cout << res;

    return 0;
}
