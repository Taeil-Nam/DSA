#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int newDenom;
    int newNumer;
    
    newDenom = denom1 * denom2;
    newNumer = (newDenom / denom1 * numer1) + (newDenom / denom2 * numer2);
    
    for (int i = 2; i <= newDenom; )
    {
        if (newDenom % i == 0 && newNumer % i == 0)
        {
            newDenom /= i;
            newNumer /= i;
        }
        else
            i++;
    }
    
    answer.push_back(newNumer);
    answer.push_back(newDenom);
    
    return answer;
}

int main()
{
    vector<int> result;

	result = solution(1, 2, 3, 4);
    cout << "numer : " << result[0] << " denom : " << result[1] << '\n';

	result = solution(9, 2, 1, 3);
    cout << "numer : " << result[0] << " denom : " << result[1] << '\n';

	result = solution(1, 2, 1, 2);
    cout << "numer : " << result[0] << " denom : " << result[1] << '\n';
	
    return 0;
}