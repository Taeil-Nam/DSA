#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<vector<int>> chickenList;

void combi(int start, vector<int>& v){
    if (v.size() == M){
        chickenList.push_back(v);
        return;
    }
    for (int i = start + 1; i < chickens.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int num;
            cin >> num;
            if (num == 1)
                houses.push_back({i, j});
            if (num == 2)
                chickens.push_back({i, j});
        }
    }
    vector<int> v;
    combi(-1, v);
    
    int res = 10000000;
    for (vector<int> cList : chickenList){
        int ChickenDist = 0;
        for (pair<int, int> house : houses){
            int minDist = 10000000;
            for (int chicken : cList){
                int dist = abs(house.first - chickens[chicken].first) + abs(house.second - chickens[chicken].second);
                minDist = min(minDist, dist);
            }
            ChickenDist += minDist;
        }
        res = min(res, ChickenDist);
    }
    cout << res;

    return 0;
}