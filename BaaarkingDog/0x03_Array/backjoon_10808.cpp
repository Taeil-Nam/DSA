#include <string>
#include <iostream>

using namespace std;

int main()
{
    const int len = 'z' - 'a' + 1;
    int alpha[len];
    string word;

    for (int i = 0; i < len; i++)
        alpha[i] = 0;

    getline(cin, word);
    for (int i = 0; i < word.size(); i++)
        alpha[word[i] - 'a']++;

    for (int i = 0; i < len; i++)
        cout << alpha[i] << ' ';

    return 0;
}