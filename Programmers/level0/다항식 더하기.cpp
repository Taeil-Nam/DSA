#include <string>
#include <vector>
#include <iostream>

using namespace std;

void itoa(string* result, int n)
{
    char c;
    int mod = n % 10;
    
    c = mod + '0';
    n /= 10;
    if (n != 0)
        itoa(result, n);
    result->push_back(c);
}

string solution(string polynomial) {
    int i = 0;
    int sum = 0;
    int sumX = 0;
    int sumC = 0;
    int flagX = 0;
    int flagY = 0;
    string result;
    
    while (i < polynomial.size())
    {
        sum = 0;
        while ('0' <= polynomial[i] && polynomial[i] <= '9')
        {
            sum = (sum * 10) + polynomial[i] - '0';
            i++;
        }
        if (polynomial[i] == 'x' && sum != 0)
        {
            sumX += sum;
            flagX = 1;
        }
        else if (polynomial[i] == 'x' && sum == 0)
        {
            sumX += 1;
            flagX = 1;
        }
        else if ((i != 0) && ('0' <= polynomial[i - 1] && polynomial[i - 1] <= '9'))
        {
            sumC += sum;
            flagY = 1;
        }
        i++;
    }
    if (flagX == 1 && flagY == 1)
    {
        if (sumX != 1)
            itoa(&result, sumX);
        result.push_back('x');
        result.push_back(' ');
        result.push_back('+');
        result.push_back(' ');
        itoa(&result, sumC);
    }
    else if (flagX == 1 && flagY == 0)
    {
        if (sumX != 1)
            itoa(&result, sumX);
        result.push_back('x');
    }
    else if (flagX == 0 && flagY == 1)
    {
        itoa(&result, sumC);
    }
    else
    {
        result = "";
    }
    
    return result;
}

int main()
{
	cout << solution("x") << endl;
	cout << solution("x + x + x") << endl;
	cout << solution("3x + 6x + 1243x") << endl;
	cout << solution("0") << endl;
	cout << solution("42 + 42") << endl;
	cout << solution("0 + 42x + 42") << endl;
	cout << solution("") << endl;
	return 0;
}