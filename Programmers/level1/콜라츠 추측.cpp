#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int count = 0;
    long long num_l = num;
    
    if (num == 1)
        return 0;

    while (num_l != 1)
    {
        if (count >= 500)
            return -1;
        if (num_l % 2 == 0)
        {
            num_l /= 2;
            count++;
        }
        else
        {
            num_l = (num_l * 3) + 1;
            count++;
        }
    }
    
    return count;
}
