#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int N, M, res;
int map[51][51];
vector<pair<int, int>> lands;
int visited[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    cin.ignore();
    for (int i = 0; i < N; i++){
        string input;
        getline(cin, input);
        for (int j = 0; j < M; j++){
            map[i][j] = input[j];
            if (input[j] == 'L')
                lands.push_back({i, j});
        }
    }
    for (pair<int, int> srcLand : lands){
        queue<pair<int, int>> q;
        memset(visited, 0, sizeof(visited));
        visited[srcLand.first][srcLand.second] = 1;
        q.push({srcLand.first, srcLand.second});
        while (q.size()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (visited[ny][nx] || map[ny][nx] != 'L') continue;
                visited[ny][nx] = visited[y][x] + 1;
                res = max(res, visited[ny][nx]);
                q.push({ny, nx});
            }
        }
    }
    cout << res - 1;

    return 0;
}