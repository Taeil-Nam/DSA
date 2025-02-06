#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> seminars;
    for (int i = 0; i < N; i++){
        int cost, day;
        cin >> cost >> day;
        seminars.push_back({day, cost});
    }
    sort(seminars.begin(), seminars.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& seminar : seminars){
        pq.push(seminar.second);
        if (pq.size() > seminar.first)
            pq.pop();
    }
    int amount = 0;
    while (pq.size()){
        amount += pq.top();
        pq.pop();
    }
    cout << amount;

    return 0;
}