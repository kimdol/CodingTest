#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void Input()
{

}

int FindCost(int n, const std::vector<int> prices, const std::vector<int> distances)
{
    // base case
    if (n <= 0)
    {
        return 0;
    }

    int min{};
    int ret{};

    for (int i = 1; i <= n; i++)
    {
        int distanceSum{ 0 };
        for (int k = 0; k < i; k++)
        {
            distanceSum += distances[k];
        }
        ret = FindCost(n - i, prices, distances) + distanceSum;
        if (i == 0 && min > ret)
        {
            min = ret;
        }
    }

    return min;

}


int main()
{
    

    return 0;
}