#include <iostream>
#include <vector>

using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void DFS(int from){
    visited[from] = true;
    cout << from << "\n";
    for(int to : adj[from]){
        if(visited[to] == false){
            DFS(to);
        }
    }
    cout << from << "로부터 시작된 함수가 종료되었습니다.\n";
    return;
}

int main(){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[4].push_back(2);

    DFS(1);
}
/*
1
2
4
4로부터
5
5로부터
2로부터
3
3로부터
1로부터
*/