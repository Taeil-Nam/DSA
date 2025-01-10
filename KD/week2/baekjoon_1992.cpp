#include <iostream>
#include <string>

using namespace std;

int N;
int map[65][65];

string go(int y, int x, int size){
    if (size == 1)
        return string(1, map[y][x]);
    char val = map[y][x];
    string ret;
    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){
            if (val != map[i][j]){
                ret += "(";
                ret += go(y, x, size / 2);
                ret += go(y, x + size / 2, size / 2);
                ret += go(y + size / 2, x, size / 2);
                ret += go(y + size / 2, x + size / 2, size / 2);
                ret += ")";
                return ret;
            }
        }
    }
    return string(1, val);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        string input;
        cin >> input;
        for (int j = 0; j < N; j++){
            map[i][j] = input[j];
        }
    }
    cout << go(0, 0, N);

    return 0;
}

/*
Divide and Conquer
- 네 가지 경우로 분할 정복하는 문제.
- 분할되었을 때 각각의 함수에서 시작점과 탐색 범위 설정 잘하면 됨.
*/