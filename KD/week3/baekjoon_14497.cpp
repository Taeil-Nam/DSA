#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
pair<int, int> J, S;
int map[301][301];
queue<pair<int, int>> q;
int visited[301][301];
int cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    cin >> J.first >> J.second >> S.first >> S.second;
    J.first--; J.second--; S.first--; S.second--;
    for (int i = 0; i < N; i++){
        string input;
        cin >> input;
        for (int j = 0; j < M; j++){
            map[i][j] = input[j];
        }
    }
    visited[J.first][J.second] = 1;
    q.push(J);
    while (true){
        cnt++;
        queue<pair<int, int>> wait;
        while (q.size()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (visited[ny][nx]) continue;
                if (ny == S.first && nx == S.second){
                    cout << cnt;
                    return 0;
                }
                visited[ny][nx] = visited[y][x] + 1;
                if (map[ny][nx] == '1'){
                    map[ny][nx] = '0';
                    wait.push({ny, nx});
                    continue;
                }
                q.push({ny, nx});
            }
        }
        q = wait;
    }

    return 0;
}