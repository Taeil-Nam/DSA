#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    vector<string> v;
    cin >> N;
    for (int i = 0; i < N; i++){
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++){
            string num = "";
            if (isdigit(input[j])){
                while (isdigit(input[j]) && j < input.size()){
                    num += input[j];
                    j++;
                }
                while (num.size() && num.front() == '0')
                    num.erase(num.begin());
                if (num.size() == 0)
                    num += '0';
                v.push_back(num);
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto num : v)
        cout << num << "\n";

    return 0;
}