#include <iostream>
#include <queue>

using namespace std;

const int maxN = 500000;
int N, K;
int turn = 1;
bool finish;
int visited[2][maxN + 1];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    if (N == K){
        cout << 0;
        return 0;
    }
    visited[0][N] = 1;
    q.push(N);
    while (q.size()){
        K += turn;
        if (K > maxN)
            break;
        if (visited[turn % 2][K]){
            finish = true;
            break;
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++){
            int here = q.front();
            q.pop();
            for (int there : {here - 1, here + 1, here * 2}){
                if (there < 0 || there > maxN || visited[turn % 2][there]) continue;
                if (there == K){
                    finish = true;
                    break;
                }
                visited[turn % 2][there] = visited[(turn + 1) % 2][here] + 1;
                q.push(there);
            }
            if (finish) break;
        }
        if (finish) break;
        turn++;
    }
    if (finish)
        cout << turn;
    else
        cout << -1;

    return 0;
}