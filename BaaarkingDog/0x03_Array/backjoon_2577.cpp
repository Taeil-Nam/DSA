#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int mul;
    int digits[10] = {};

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    mul = a * b * c;
    while (mul > 0)
    {
        digits[mul % 10]++;
        mul /= 10;
    }

    for (auto value : digits)
        cout << value << "\n";

    return 0;
}