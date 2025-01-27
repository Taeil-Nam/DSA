#include <iostream>
#include <string>

using namespace std;

int K;
long long maxRes = 0;
long long minRes = 10000000000;
char ops[10];
int nums[10];

void makePermutation(int n, int r, int depth){
    if (depth == r){
        long long num = 0;
        for (int i = 0; i < K; i++){
            if (ops[i] == '<' && nums[i] < nums[i + 1]) continue;
            else if (ops[i] == '>' && nums[i] > nums[i + 1]) continue;
            else return;
        }
        for (int i = 0; i < r; i++){
            num = num * 10 + nums[i];
        }
        maxRes = max(maxRes, num);
        minRes = min(minRes, num);
        return;
    }
    for (int i = depth; i < n; i++){
        swap(nums[i], nums[depth]);
        makePermutation(n, r, depth + 1);
        swap(nums[i], nums[depth]);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> K;
    for (int i = 0; i < K; i++){
        cin >> ops[i];
    }
    for (int i = 0; i <= 9; i++){
        nums[i] = i;
    }
    makePermutation(10, K + 1, 0);
    string maxResStr = to_string(maxRes);
    string minResStr = to_string(minRes);
    if (maxResStr.size() <= K)
        maxResStr = '0' + maxResStr;
    if (minResStr.size() <= K)
        minResStr = '0' + minResStr;
    cout << maxResStr << "\n" << minResStr;
    
    return 0;
}