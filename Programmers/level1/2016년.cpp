#include <string>
#include <vector>

using namespace std;

int TotalDayOfMonth(int month)
{
    if (month == 2)
        return 29;
    if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    if (month == 1 || month == 3 || month == 5 || month == 7
        || month == 8 || month == 10 || month || 12)
        return 31;
    return 0;
}

string solution(int a, int b)
{
    vector<string> week = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int sum = 0;
    int week_i = 0;

    for(int i = 1; i <= a; i++)
        sum += TotalDayOfMonth(i);
    sum = sum - TotalDayOfMonth(a) + b;
    week_i = sum % 7;
    
    return week[week_i];
}
