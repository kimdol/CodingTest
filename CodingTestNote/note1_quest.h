#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 백트래킹 함수
void MaxCnt1(const vector<vector<int>>& quest, int currentXp, int qCnt, vector<bool>& visits, int& maxValue)
{
    // 최대값 갱신
    maxValue = max(maxValue, qCnt);

    for (int i = 0; i < quest.size(); ++i)
    {
        int required = quest[i][0];
        int reward = quest[i][1];

        if (!visits[i] && currentXp >= required) 
        {
            visits[i] = true;
            MaxCnt1(quest, currentXp - required + reward, qCnt + 1, visits, maxValue);
            visits[i] = false; // 백트래킹
        }
    }
}

int solution1(vector<vector<int>> quest)
{
    int maxValue = 0;
    vector<bool> visits(quest.size(), false);

    MaxCnt1(quest, 0, 0, visits, maxValue);

    return maxValue;
}