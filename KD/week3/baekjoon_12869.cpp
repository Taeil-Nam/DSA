#include <iostream>
#include <queue>

using namespace std;

int N;
int scvs[3];
int visited[61][61][61];
struct HP{
    int hp1, hp2, hp3;
};
queue<HP> q;
int damages[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9},
};

int solve(int scv1, int scv2, int scv3){
    visited[scv1][scv2][scv3] = 1;
    q.push({scv1, scv2, scv3});
    while (q.size()){
        int scv1 = q.front().hp1;
        int scv2 = q.front().hp2;
        int scv3 = q.front().hp3;
        q.pop();
        for (int i = 0; i < 6; i++){
            int nscv1 = max(0, scv1 - damages[i][0]);
            int nscv2 = max(0, scv2 - damages[i][1]);
            int nscv3 = max(0, scv3 - damages[i][2]);
            if (nscv1 == 0 && nscv2 == 0 && nscv3 == 0)
                return visited[scv1][scv2][scv3];
            if (visited[nscv1][nscv2][nscv3]) continue;
            visited[nscv1][nscv2][nscv3] = visited[scv1][scv2][scv3] + 1;
            q.push({nscv1, nscv2, nscv3});
        }
    }
    return visited[scv1][scv2][scv3];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> scvs[i];
    }
    cout << solve(scvs[0], scvs[1], scvs[2]);

    return 0;
}