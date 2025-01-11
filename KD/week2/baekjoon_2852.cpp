#include <iostream>
#include <string>

using namespace std;

#define time tnam1

int N, scoring, score1, score2, res1, res2;
string time, prevTime;

void print(int time){
    string m = "0" + to_string(time / 60);
    string s = "0" + to_string(time % 60);
    cout << m.substr(m.size() - 2, 2) << ":" << s.substr(s.size() - 2, 2) << "\n";
}

int timeToInt(const string& time){
    return atoi(time.substr(0, 2).c_str()) * 60 + atoi(time.substr(3, 2).c_str());
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> scoring >> time;
        if (score1 > score2)
            res1 += timeToInt(time) - timeToInt(prevTime);
        else if (score1 < score2)
            res2 += timeToInt(time) - timeToInt(prevTime);
        if (scoring == 1) score1++;
        else if (scoring == 2) score2++;
        prevTime = time;
    }
    if (score1 > score2)
        res1 += timeToInt("48:00") - timeToInt(prevTime);
    else if (score1 < score2)
        res2 += timeToInt("48:00") - timeToInt(prevTime);
    print(res1);
    print(res2);

    return 0;
}