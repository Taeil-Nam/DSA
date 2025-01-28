#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double GetStageReachCount(vector<int>& stages, int stage)
{
    double reachCount = 0;

    for (int i = 0; i < stages.size(); i++)
    {
        if (stages[i] >= stage)
            reachCount++;
    }
    return reachCount;
}

double GetStageFailCount(vector<int>& stages, int stage)
{
    double failCount = 0;

    for (int i = 0; i < stages.size(); i++)
    {
        if (stages[i] == stage)
            failCount++;
    }
    return failCount;
}


int GetMaxFailStage(vector<double>& failRate)
{
    double maxFailRate = -1.0;
    int maxFailStage = 0;
    
    for (int stage = 0; stage < failRate.size(); stage++)
    {
        if (failRate[stage] > maxFailRate)
        {
            maxFailRate = failRate[stage];
            maxFailStage = stage + 1;
        }
    }
    failRate[maxFailStage - 1] = -1;
    return maxFailStage;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<double> failRate;
    double stageFailCount = 0;
    double stageReachCount = 0;

    for (int stage = 1; stage <= N; stage++)
    {
        stageFailCount = GetStageFailCount(stages, stage);
        stageReachCount = GetStageReachCount(stages, stage);
        if (stageReachCount == 0)
            failRate.push_back(0);
        else
            failRate.push_back(stageFailCount / stageReachCount);
    }
    for (int stage = 1; stage <= N; stage++)
        answer.push_back(GetMaxFailStage(failRate));

    return answer;    
}
