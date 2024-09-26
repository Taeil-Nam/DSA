#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) // O(n)
    {
        deque<int> DQ;
        string order;
        string nums;
        int size;
        int num = 0;
        bool isError = false;
        bool isReverse = false;
        cin >> order >> size >> nums;
        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            if (::isdigit(nums[i]))
            {
                if (::isdigit(nums[i - 1]))
                    num *= 10;
                num += nums[i] - '0';
            }
            else if (nums[i] == ',' || (nums[i] == ']' && nums.size() != 2))
            {
                DQ.push_back(num);
                num = 0;
            }
        }
        for (auto c : order) // O(n)
        {
            if (c == 'R')
                isReverse = 1 - isReverse;
            else if (c == 'D')
            {
                if (DQ.empty())
                {
                    isError = true;
                    cout << "error\n";
                    break;
                }
                if (isReverse == false)
                    DQ.pop_front();
                else
                    DQ.pop_back();
            }
        }
        if (isError)
            continue;
        if (isReverse)
            ::reverse(DQ.begin(), DQ.end()); // O(n)
        cout << "[";
        for (auto it = DQ.begin(); it != DQ.end(); it++)
        {
            if (it < DQ.end() - 1)
                cout << *it << ",";
            else
                cout << *it;
        }
        cout << "]\n";
    }
    
    return 0;
}
/*
Time Complexity = O(n^2)
Space Complexity = O(n)

풀이
덱 자료구조 사용.
R이면 isReverse = 1 - isReverse; 코드로 0과 1을 왔다갔다 함.
D이면 isReverse 값에 따라 pop_front() 또는 pop_back() 수행하면 됨.

isReverse 값에 따라, 덱의 앞과 뒤 중 어디서 값을 추출할지 결정.
RD 명령어들이 끝나고 isReverse = 1인 경우, 덱에 ::reverse() 수행.

입력 값 파싱과, 결과 출력에 대부분의 시간을 쏟음.
*/
