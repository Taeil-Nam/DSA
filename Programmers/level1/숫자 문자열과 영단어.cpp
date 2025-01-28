#include <string>
#include <vector>

using namespace std;

void find_number(string &num, int &answer)
{
	if (num == "zero")
	{
		num = "";
		answer = answer * 10;
	}
	if (num == "one")
	{
		num = "";
		answer = answer * 10 + 1;
	}
	else if (num == "two")
	{
		num = "";
		answer = answer * 10 + 2;
	}
	else if (num == "three")
	{
		num = "";
		answer = answer * 10 + 3;
	}
	else if (num == "four")
	{
		num = "";
		answer = answer * 10 + 4;
	}
	else if (num == "five")
	{
		num = "";
		answer = answer * 10 + 5;
	}
	else if (num == "six")
	{
		num = "";
		answer = answer * 10 + 6;
	}
	else if (num == "seven")
	{
		num = "";
		answer = answer * 10 + 7;
	}
	else if (num == "eight")
	{
		num = "";
		answer = answer * 10 + 8;
	}
	else if (num == "nine")
	{
		num = "";
		answer = answer * 10 + 9;
	}
}

int solution(string s)
{
	int answer = 0;
	string num = "";

	for (int i = 0; i < s.size(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			num = "";
			answer = answer * 10 + s[i] - '0';
			continue;
		}
		num.push_back(s[i]);
		find_number(num, answer);
	}

	return answer;
}
