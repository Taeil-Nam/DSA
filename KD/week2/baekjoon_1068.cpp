#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[51];
int root, target;

int dfs(int here){
    int ret = 0;
    int child = 0;
    for (int there : adj[here]){
        if (there == target)
            continue;
        ret += dfs(there);
        child++;
    }
    if (child == 0)
        return 1;
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        if (num == -1)
            root = i;
        else
            adj[num].push_back(i);
    }
    cin >> target;
    if (target == root){
        cout << 0;
        return 0;
    }
    cout << dfs(root);

    return 0;
}