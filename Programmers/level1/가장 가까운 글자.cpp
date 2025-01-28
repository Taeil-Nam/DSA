#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
	vector<int> answer;
	int first_word = -1;
	int diff = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0)
		{
			answer.push_back(first_word);
			continue;
		}
		else
		{
			diff = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				diff++;
				if (s[j] == s[i])
				{
					answer.push_back(diff);
					break;
				}
				if (j == 0)
				{
					answer.push_back(first_word);
				}
			}
		}
	}

	return answer;
}
