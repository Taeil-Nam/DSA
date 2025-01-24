#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define prev tnam

int N, K;
int minCnt = INT_MAX;
int visited[200001];
int prev[200001];
vector<int> res;
queue<int> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    visited[N] = 1;
    q.push(N);
    while (q.size()){
        int here = q.front();
        q.pop();
        if (here == K){
            minCnt = min(minCnt, visited[here]);
            break;
        }
        for (auto there : {here - 1, here + 1, here * 2}){
            if (0 <= there && there <= 200000){
                if (visited[there]) continue;
                visited[there] = visited[here] + 1;
                prev[there] = here;
                q.push(there);
            }
        }
    }
    for (int i = K; i != N; i = prev[i]){
        res.push_back(i);
    }
    res.push_back(N);
    reverse(res.begin(), res.end());
    cout << minCnt - 1 << "\n";
    for (auto n : res)
        cout << n << " ";
    
    return 0;
}