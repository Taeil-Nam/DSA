#include <iostream>
#include <vector>

using namespace std;

int N, L, R, res;
int map[51][51];
int visited[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> conturies;
int sum, cnt;

void dfs(int y, int x){
    visited[y][x] = 1;
    sum += map[y][x];
    cnt++;
    conturies.push_back({y, x});
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (visited[ny][nx]) continue;
        int diff = abs(map[ny][nx] - map[y][x]);
        if (L <= diff && diff <= R){
            dfs(ny, nx);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    while (true){
        bool flag = false;
        fill(&visited[0][0], &visited[0][0] + (51 * 51), 0);
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (visited[i][j]) continue;
                conturies.clear();
                sum = 0;
                cnt = 0;
                dfs(i, j);
                for (auto contury : conturies){
                    map[contury.first][contury.second] = sum / cnt;
                }
                if (conturies.size() >= 2)
                    flag = true;
            }
        }
        if (flag == false)
            break;
        res++;
    }
    cout << res;

    return 0;
}