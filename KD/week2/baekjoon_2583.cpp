#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int M, N, K, cnt, area;
vector<int> areas;
int map[101][101];
int visited[101][101];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x){
    visited[y][x] = 1;
    area++;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N)
            continue;
        if (visited[ny][nx] || map[ny][nx])
            continue;
        dfs(ny, nx);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int y = ly; y < ry; y++){
            for (int x = lx; x < rx; x++){
                map[y][x] = 1;
            }
        }
    }
    for (int y = 0; y < M; y++){
        for (int x = 0; x < N; x++){
            area = 0;
            if (visited[y][x] || map[y][x])
                continue;
            dfs(y, x);
            cnt++;
            areas.push_back(area);
        }
    }
    cout << cnt << "\n";
    sort(areas.begin(), areas.end());
    for(auto area : areas)
        cout << area << " ";
    return 0;
}