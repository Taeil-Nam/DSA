#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> cows;
    for (int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        cows.push_back({start, end});
    }
    sort(cows.begin(), cows.end());
    int end = cows[0].first + cows[0].second;
    for (int i = 1; i < cows.size(); i++){
        auto& cow = cows[i];
        if (cow.first < end){
            end += cow.second;
        }
        else{
            end = cow.first + cow.second;
        }
    }
    cout << end;

    return 0;
}

/*
s    e
------
   ------
   s    e

s   e
-----
    -----
    s   e

s   e
-----
       -----
       s   e
*/