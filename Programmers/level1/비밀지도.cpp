#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void MakeBinary(vector<int> &bin, int dec, int n)
{
	while (n > 0)
	{
		bin.push_back(dec % 2);
		dec /= 2;
		n--;
	}
	reverse(bin.begin(), bin.end());
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;

	for (int i = 0; i < n; i++)
	{
		int dec1 = arr1[i];
		int dec2 = arr2[i];
		vector<int> bin1;
		vector<int> bin2;
		string row;

		MakeBinary(bin1, dec1, n);
		MakeBinary(bin2, dec2, n);
		for (int j = 0; j < n; j++)
		{
			if (bin1[j] == 0 && bin2[j] == 0)
				row.push_back(' ');
			else
				row.push_back('#');
		}
		answer.push_back(row);
	}

	return answer;
}
