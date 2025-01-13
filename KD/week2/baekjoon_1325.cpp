#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[10001];
int map[10001];
int visited[10001];
int mx;

int dfs(int here){
    visited[here] = 1;
    int ret = 1;
    for (int there : adj[here]){
        if (visited[there])
            continue;
        ret += dfs(there);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    while (M--){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++){
        memset(visited, 0, sizeof(visited));
        map[i] = dfs(i);
        mx = max(map[i], mx);
    }
    for (int i = 1; i <= N; i++){
        if (map[i] == mx)
            cout << i << " ";
    }

    return 0;
}