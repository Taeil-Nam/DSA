#include <iostream>

using namespace std;

int N, M, H;
bool radder[35][35];
int res = 314;

bool isMatch(){
    for (int x = 1; x <= N; x++){
        int pos = x;
        for (int y = 1; y <= H; y++){
            if (radder[y][pos]) pos++;
            else if (radder[y][pos - 1]) pos--;
        }
        if (pos != x) return false;
    }
    return true;
}

void go(int here, int cnt){
    if (cnt > 3 || cnt >= res) return;
    if (isMatch()){
        res = min(res, cnt);
        return;
    }
    for (int y = here; y <= H; y++){
        for (int x = 1; x < N; x++){
            if (radder[y][x] || radder[y][x - 1] || radder[y][x + 1]) continue;
            radder[y][x] = true;
            go(y, cnt + 1);
            radder[y][x] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        radder[a][b] = true;
    }
    go (1, 0);
    if (res == 314)
        cout << -1;
    else
        cout << res;

    return 0;
}