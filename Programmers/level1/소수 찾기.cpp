#include <string>
#include <vector>

using namespace std;

vector<int> Era(vector<bool> &che, int maxNum)
{
	vector<int> v;

	for (int i = 2; i <= maxNum; i++)
	{
		if (che[i])
			continue;
		for (int j = i * 2; j <= maxNum; j += i)
			che[j] = 1;
	}
	for (int i = 2; i <= maxNum; i++)
	{
		if (che[i] == false)
			v.push_back(i);
	}
	return v;
}

int solution(int n)
{
	vector<bool> che(n, 0);

	return Era(che, n).size();
}
