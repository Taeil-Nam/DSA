#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[1004];
int visited[1004];

void postOrder(int here){
    if (visited[here] == false){
        if (adj[here].size() == 1)
            postOrder(adj[here][0]);
        if (adj[here].size() == 2){
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
        visited[here] = true;
        cout << here << ' ';
    }
}

void preOrder(int here){
    if (visited[here] == false){
        visited[here] = true;
        cout << here << ' ';
        if (adj[here].size() == 1)
            preOrder(adj[here][0]);
        if (adj[here].size() == 2){
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}

void inOrder(int here){
    if (visited[here] == false){
        if (adj[here].size() == 1){
            inOrder(adj[here][0]);
            visited[here] = true;
            cout << here << ' ';
        }
        else if (adj[here].size() == 2){
            inOrder(adj[here][0]);
            visited[here] = true;
            cout << here << ' ';
            inOrder(adj[here][1]);
        }
        else{
            visited[here] = true;
            cout << here << ' ';
        }
    }
}

int main(){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;
    cout << "\n 트리순회 : postOrder(후위) \n";
    postOrder(root);
    memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : preOrder(전위) \n";
    preOrder(root);
    memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : inOrder(중위) \n";
    inOrder(root);
}
