#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n = 4, r = 3, depth = 0;

void printV(vector<int> &v)
{
    for(int i = 0; i < r; i++)
        cout << v[i] << " ";
    cout << "\n";
}

void makePermutation(int n, int r, int depth)
{
    //cout << n << " : " << r << " : " << depth << '\n';
    if (r == depth){
        printV(v);
        return;
    }
    for (int i = depth; i < n; i++){
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
    return;
}

int main()
{
    for(int i = 1; i <= n; i++) v.push_back(i);
    makePermutation(n, r, depth);

    return 0;
}