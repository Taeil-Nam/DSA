#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> nums;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int res = 0;
    for (int i = 0; i < nums.size(); i++){
        unordered_map<int, int> freq;
        int target = nums[i];
        for (int j = 0; j < nums.size(); j++){
            if (j == i)
                continue;
            if (freq.count(target - nums[j]) > 0){
                res++;
                break;
            }
            freq[nums[j]]++;
        }
    }
    cout << res;

    return 0;
}
