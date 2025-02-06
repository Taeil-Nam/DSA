#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    vector<pair<int, int>> problems;
    cin >> N;
    for (int i = 0; i < N; i++){
        int deadline, cup;
        cin >> deadline >> cup;
        problems.push_back({deadline, cup});
    }
    sort(problems.begin(), problems.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& problem : problems){
        pq.push(problem.second);
        if (pq.size() > problem.first)
            pq.pop();
    }
    int res = 0;
    while (pq.size()){
        res += pq.top();
        pq.pop();
    }
    cout << res;

    return 0;
}
