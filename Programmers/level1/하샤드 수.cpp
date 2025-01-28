#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum_digit = 0;

    for (int temp_x = x; temp_x > 0; )
    {
        sum_digit += temp_x % 10;
        temp_x /= 10;
    }

    if (x % sum_digit == 0)
        return true;
    else
        return false;
}
