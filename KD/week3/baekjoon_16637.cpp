#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int N;
int res = INT_MIN;
string input;
vector<int> nums;
vector<char> operators;

int cal(char op, int a, int b){
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}

void go(int here, int val){
    if (here == nums.size() - 1){
        res = max(res, val);
        return;
    }
    go(here + 1, cal(operators[here], val, nums[here + 1]));
    if (here + 2 < nums.size()){
        int rightSum = cal(operators[here + 1], nums[here + 1], nums[here + 2]);
        go(here + 2, cal(operators[here], val, rightSum));
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> input;
    for (int i = 0; i < N; i++){
        if (i % 2 == 0)
            nums.push_back(input[i] - '0');
        else
            operators.push_back(input[i]);
    }
    go(0, nums[0]);
    cout << res;

    return 0;
}