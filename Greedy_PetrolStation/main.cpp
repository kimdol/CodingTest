#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::istream& operator >> (std::istream& is, std::vector<int>& v)
{
    // 스트림 분석
   /* while (1)
    {
        char input{};
        is.get(input);
        if (input == '\n')
        {
            break;
        }
        v.push_back(input - '0');
    }

    return is;
    */
    int input;

    is >> input;

    v.push_back(input);

    return is;
}

void Input(int& n, std::vector<int>& prices, std::vector<int>& distances)
{
    // 스트림 분석
    /*
    std::cin >> n;
    std::cin.ignore(INT_MAX, '\n');
    std::cin >> prices;
    std::cin >> distances;
    */
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> prices;
    }

    for (int i = 0; i < n-1; i++)
    {
        std::cin >> distances;
    }
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
    int n{};
    std::vector<int> vPrices{}, vDistances{};

    Input(n, vPrices, vDistances);
    std::cout << FindCost(n, vPrices, vDistances) << std::endl;

    return 0;
}