#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[10][10];
vector<pair<int, int>> virusPos;
vector<pair<int, int>> emptyPos;
int ret;
int visited[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        if (visited[ny][nx] || map[ny][nx] == 1)
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
            if (map[i][j] == 0) emptyPos.push_back({i, j});
            if (map[i][j] == 2) virusPos.push_back({i, j});
        }
    }
    for (int i = 0; i < emptyPos.size(); i++){
        for (int j = i + 1; j < emptyPos.size(); j++){
            for (int k = j + 1; k < emptyPos.size(); k++){
                int cnt = 0;
                fill(&visited[0][0], &visited[0][0] + (10 * 10), 0);
                map[emptyPos[i].first][emptyPos[i].second] = 1;
                map[emptyPos[j].first][emptyPos[j].second] = 1;
                map[emptyPos[k].first][emptyPos[k].second] = 1;
                for (auto pos : virusPos)
                    dfs(pos.first, pos.second);
                for (int y = 0; y < N; y++){
                    for (int x = 0; x < M; x++){
                        if (map[y][x] == 0 && visited[y][x] == false)
                            cnt++;
                    }
                }
                ret = max(ret, cnt);
                map[emptyPos[i].first][emptyPos[i].second] = 0;
                map[emptyPos[j].first][emptyPos[j].second] = 0;
                map[emptyPos[k].first][emptyPos[k].second] = 0;
            }
        }
    }
    cout << ret;

    return 0;
}