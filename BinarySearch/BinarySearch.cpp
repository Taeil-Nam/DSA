#include <iostream>
#include <vector>

int BinarySearch(std::vector<int>& v, int low, int high, int key)
{

	while (low <= high)
	{
		int mid = (low + high) / 2;
		
		if (key == v[mid])
		{
			return mid;
		}
		else if (key < v[mid])
		{
			high = mid - 1;	
		}
		else if (key > v[mid])
		{
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	std::vector<int> v;
	int size = 16;

	for (int i = 0; i < size; i++)
	{
		v.push_back(i);
	}

	int low = 0;
	int high = v.size() - 1;
	int target = 10;
	std::cout << BinarySearch(v, low, high, target) << std::endl;

	return 0;
}
