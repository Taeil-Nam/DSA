#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K;
vector<int> nums;
vector<vector<int>> res(14);

void go(int start, int end, int level){
    if (start > end)
        return;
    if (start == end){
        res[level].push_back(nums[start]);
        return;
    }
    int mid = (start + end) / 2;
    res[level].push_back(nums[mid]);
    go(start, mid - 1, level + 1);
    go(mid + 1, end, level + 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> K;
    for (int i = 0; i < pow(2, K) - 1; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    go(0, pow(2, K) - 1, 1);
    for (int i = 1; i <= K; i++){
        for (int n : res[i])
            cout << n << " ";
        cout << "\n";
    }

    return 0;
}