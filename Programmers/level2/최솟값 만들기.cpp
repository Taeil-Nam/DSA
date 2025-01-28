#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());   // vector 오름차순 정렬
    sort(B.rbegin(), B.rend()); // vector 내림차순 정렬
    
    while (A.size() != 0)
    {
        answer += A[0] * B[0];
        A.erase(A.begin()); // A 벡터 첫 번째 원소 제거
        B.erase(B.begin()); // B 벡터 첫 번째 원소 제거
    }

    return answer;
}
