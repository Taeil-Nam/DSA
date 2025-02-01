#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, P, D;
    vector<pair<int, int>> seminars;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> P >> D;
        seminars.push_back({D, P});
    }
    sort(seminars.begin(), seminars.end());
    int amount = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& seminar : seminars){
        pq.push(seminar.second);
        if (pq.size() > seminar.first)
            pq.pop();
    }
    while (pq.size()){
        amount += pq.top();
        pq.pop();
    }
    cout << amount;

    return 0;
}
