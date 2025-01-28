#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int sum = 0;
    bool is_in = false;
    
    for (int num = 0; num <= 9; num++)
    {
        is_in = false;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (num == numbers[i])
                is_in = true;
        }
        if (is_in == false)
            sum += num;
    }
    
    return sum;
}
