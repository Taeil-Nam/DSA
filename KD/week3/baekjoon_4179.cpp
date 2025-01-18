#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
char map[1001][1001];
int fireTime[1001][1001];
int escapeTime[1001][1001];
int sy, sx;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

#define INF 10000000

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    cin.ignore();
    // fireTime 값들을 INF 값으로 초기화 필수
    fill(&fireTime[0][0], &fireTime[0][0] + (1001 * 1001), INF);
    for (int i = 0; i < N; i++){
        string input;
        getline(cin, input);
        for (int j = 0; j < M; j++){
            map[i][j] = input[j];
            if (input[j] == 'J'){
                sy = i;
                sx = j;
                escapeTime[i][j] = 1;
            }
            if (input[j] == 'F'){
                fireTime[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (map[ny][nx] == '#' || fireTime[ny][nx] != INF) continue;
            fireTime[ny][nx] = fireTime[y][x] + 1;
            q.push({ny, nx});
        }
    }
    q.push({sy, sx});
    while (q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M){
                cout << escapeTime[y][x];
                return 0;
            }
            if (map[ny][nx] != '.' || escapeTime[ny][nx]) continue;
            if (escapeTime[y][x] + 1 >= fireTime[ny][nx]) continue;
            escapeTime[ny][nx] = escapeTime[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}