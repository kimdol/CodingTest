#include <iostream>
#include "note1_quest.h"

int main()
{
    vector<vector<int>> quest1 = 
    {
        {7, 4},
        {2, 4},
        {13, 5},
        {0, 3},
        {14, 10}
    };

    vector<vector<int>> quest2 = {
    {3, 1},  // 필요 XP 3, 보상 1
    {0, 2},  // 필요 XP 0, 보상 2
    {2, 0}   // 필요 XP 2, 보상 0
    };
    std::cout << solution1(quest1) << std::endl;
}

