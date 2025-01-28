#include <string>
#include <cmath>

using namespace std;

string& Tokenization(string& dartResult, size_t& strIndex)
{
    size_t start = strIndex;
    size_t length = 0;
    string score;
    
    if (dartResult[strIndex] == '1' && dartResult[strIndex + 1] == '0')
    {
        strIndex += 2;
        length += 2;
    }
    else
    {
        strIndex++;
        length++;
    }
    for (; strIndex < dartResult.length(); strIndex++, length++)
    {
        if ('0' <= dartResult[strIndex] && dartResult[strIndex] <= '9')
            break;
    }
    score = dartResult.substr(start, length);
    return score;
}

int GetScore(string& score)
{
    int result = 0;

    for (int i = 0; i < score.length(); i++)
    {
        if ('0' <= score[i] && score[i] <= '9')
            result = result * 10 + score[i] - '0';
        if (score[i] == 'D')
            result = result * result;
        if (score[i] == 'T')
            result = result * result * result;
        if (score[i] == '#')
            result *= -1;
    }
    return result;
}

int solution(string dartResult)
{
    string score1, score2, score3;
    int score1_n, score2_n, score3_n = 0;
    size_t strIndex = 0;

    // tokenization
    score1 = Tokenization(dartResult, strIndex);
    score2 = Tokenization(dartResult, strIndex);
    score3 = Tokenization(dartResult, strIndex);
    
    // get score
    score1_n = GetScore(score1);
    score2_n = GetScore(score2);
    score3_n = GetScore(score3);
   
    // check star bonus
    if (score1.find('*') != string::npos)
        score1_n *= 2;
    if (score2.find('*') != string::npos)
    {
        score1_n *= 2;
        score2_n *= 2;
    }
    if (score3.find('*') != string::npos)
    {
        score2_n *= 2;
        score3_n *= 2;
    }

    return score1_n + score2_n + score3_n;
}
