#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int H, W;
    cin >> H >> W;
    vector<int> res;
    for (int i = 0; i < H; i++){
        string input;
        cin >> input;
        int cpos = -1;
        for (int j = 0; j < W; j++){
            if (input[j] == 'c'){
                cpos = j;
                res.push_back(0);
            }
            else{
                if (cpos == -1)
                    res.push_back(-1);
                else
                    res.push_back(j - cpos);
            }
        }
    }
    for (int i = 1; i <= res.size(); i++){
        cout << res[i - 1];
        if (i % W == 0)
            cout << "\n";
        else
            cout << " ";
    }

    return 0;
}