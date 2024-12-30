#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string& str, const string delimiter)
{
    vector<string> res;
    auto start = 0;
    auto end = str.find(delimiter);
    while (end != string::npos)
    {
        res.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    res.push_back(str.substr(start));
    return res;
}

int main()
{
    string str = "aa->bb->cc";
    vector<string> tokens = split(str, "->");
    for (auto token : tokens) cout << token << " ";

    return 0;
}