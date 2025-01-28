#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int solution(vector<vector<int>> dots) {
    double x1, x2, x3, x4, y1, y2, y3, y4;
    
    x1 = dots[0][0];
    x2 = dots[1][0];
    x3 = dots[2][0];
    x4 = dots[3][0];
    
    y1 = dots[0][1];
    y2 = dots[1][1];
    y3 = dots[2][1];
    y4 = dots[3][1];
    
    if (abs(y1 - y2) / abs(x1 - x2) == abs(y3 - y4) / abs(x3 - x4))
            return 1;
    if (abs(y1 - y3) / abs(x1 - x3) == abs(y2 - y4) / abs(x2 - x4))
            return 1;
    if (abs(y1 - y4) / abs(x1 - x4) == abs(y2 - y3) / abs(x2 - x3))
            return 1;
    return 0;
}