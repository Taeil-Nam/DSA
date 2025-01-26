#include <iostream>
#include <string>
#include <queue>

using namespace std;

int R, C;
int map[1501][1501];
int swanY, swanX;
queue<pair<int, int>> waterQ;
queue<pair<int, int>> waterTempQ;
queue<pair<int, int>> swanQ;
queue<pair<int, int>> swanTempQ;
int waterVisited[1501][1501];
int swanVisited[1501][1501];
int day;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool CheckSwan(){
    while (swanQ.size()){
        int y = swanQ.front().first;
        int x = swanQ.front().second;
        swanQ.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || swanVisited[ny][nx]) continue;
            swanVisited[ny][nx] = swanVisited[y][x] + 1;
            if (map[ny][nx] == 'L') return true;
            else if (map[ny][nx] == '.') swanQ.push({ny, nx});
            else if (map[ny][nx] == 'X') swanTempQ.push({ny, nx});
        }
    }
    return false;
}

void WaterCheck(){
    while (waterQ.size()){
        int y = waterQ.front().first;
        int x = waterQ.front().second;
        waterQ.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || waterVisited[ny][nx]) continue;
            if (map[ny][nx] == 'X'){
                waterVisited[ny][nx] = waterVisited[y][x] + 1;
                map[ny][nx] = '.';
                waterTempQ.push({ny, nx});
            }
        }
    }
}

void ClearQ(queue<pair<int, int>>& q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        string input;
        cin >> input;
        for (int j = 0; j < C; j++){
            map[i][j] = input[j];
            if (map[i][j] == 'L'){
                swanY = i;
                swanX = j;
            }
            if (map[i][j] == 'L' || map[i][j] == '.'){
                waterVisited[i][j] = 1;
                waterQ.push({i, j});
            }
        }
    }
    swanVisited[swanY][swanX] = 1;
    swanQ.push({swanY, swanX});

    while (true){
        if (CheckSwan()) break;
        WaterCheck();
        swanQ = swanTempQ;
        waterQ = waterTempQ;
        ClearQ(swanTempQ);
        ClearQ(waterTempQ);
        day++;
    }
    cout << day;

    return 0;
}