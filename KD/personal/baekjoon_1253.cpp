#include <iostream>
#include <vector>
#include <algorithm>

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
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < N; i++){
        int target = nums[i];
        int left = 0;
        int right = N - 1;
        while (left < right){
            if (left == i) {left++; continue;}
            if (right == i) {right--; continue;}
            if (nums[left] + nums[right] == target){
                res++;
                break;
            }
            else if (nums[left] + nums[right] < target) left++;
            else if (nums[left] + nums[right] > target) right--;
        }
    }
    cout << res;

    return 0;
}
