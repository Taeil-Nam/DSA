#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2)
{
    int arr1Sum = 0;
    int arr2Sum = 0;

    if (arr1.size() > arr2.size())
        return 1;
    else if ((arr1.size() < arr2.size()))
        return -1;
    else
    {
        for (size_t i = 0; i < arr1.size(); i++)
        {
            arr1Sum += arr1[i];
            arr2Sum += arr2[i];
        }
        if (arr1Sum > arr2Sum)
            return 1;
        else if (arr1Sum < arr2Sum)
            return -1;
        else
            return 0;
    }
}
