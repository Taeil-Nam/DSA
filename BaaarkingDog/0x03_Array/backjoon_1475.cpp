#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    int digits[10] = {};
    int maxNum = 0;
    int result = 0;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;

    if (num == 0)
    {
        cout << 1;
        return 0;
    }
    while (num > 0)
    {
        digits[num % 10]++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (digits[i] > digits[maxNum])
            maxNum = i;
    }

    if (maxNum == 6 || maxNum == 9)
    {
        int sum = digits[6] + digits[9];
        if (sum % 2 == 0)
            result = sum / 2;
        else
            result = sum / 2 + 1;
    }
    else
    {
        result = digits[maxNum];
    }

    cout << result;

    return 0;
}