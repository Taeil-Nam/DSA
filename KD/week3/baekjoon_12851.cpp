#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[1000000];
int cnt[1000000];
queue<int> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    if (N == K){
        cout << "0\n1";
        return 0;
    }
    visited[N] = 1;
    cnt[N] = 1;
    q.push(N);
    while (q.size()){
        int now = q.front();
        q.pop();
        for (int next : {now - 1, now + 1, now * 2}){
            if (0 <= next && next <= 200000){
                if (!visited[next]){
                    visited[next] = visited[now] + 1;
                    q.push(next);
                    cnt[next] += cnt[now];
                }
                else if (visited[next] == visited[now] + 1)
                    cnt[next] += cnt[now];
            }
        }
    }
    cout << visited[K] - 1 << "\n" << cnt[K];

    return 0;
}