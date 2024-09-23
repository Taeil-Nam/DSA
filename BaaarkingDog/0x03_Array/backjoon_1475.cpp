#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num = 0;
    int maxNum = 0;
    int digits[10] = {};

    cin >> num;

    if (num == 0)
    {
        cout << 1;
        return 0;
    }

    while (num)
    {
        digits[num % 10]++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9) continue;
        maxNum = max(maxNum, digits[i]);
    }
    maxNum = max(maxNum, (digits[6] + digits[9] + 1) / 2);
    cout << maxNum;

    return 0;
}