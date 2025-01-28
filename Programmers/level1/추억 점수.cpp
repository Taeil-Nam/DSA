#include <string>
#include <vector>

using namespace std;

int FindNameValue(vector<string> &name, vector<int> &yearning, string targetName)
{
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] == targetName)
		{
			return (yearning[i]);
		}
	}
	return (0);
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
	vector<int> answer;
	int sum = 0;

	for (int i = 0; i < photo.size(); i++)
	{
		sum = 0;
		for (int j = 0; j < photo[i].size(); j++)
		{
			sum += FindNameValue(name, yearning, photo[i][j]);
		}
		answer.push_back(sum);
	}
	return answer;
}
