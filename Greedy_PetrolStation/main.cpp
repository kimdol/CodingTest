#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <memory>

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

    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> distances;
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> prices;
    }

}

using cost_history = std::map<int, long long>;
long long FindCost(const int& total, int n, const std::vector<int>& prices, const std::vector<int>& distances, cost_history& h)
{
    if (h.count(n) == 1)
    {
        return h[n];
    }

    // base case
    if (n <= 0)
    {
        return 0;
    }

    long long min{};
    long long ret{};

    for (int i = 1; i <= n; i++)
    {
        std::vector<int>::const_iterator it{ distances.begin() + (total - n) };
        long long distanceSum{ std::accumulate(it, it + i, 0LL) };

        ret = FindCost(total, n - i, prices, distances, h) + (prices[total - n] * distanceSum);
        if (i == 1 || min > ret)
        {
            min = ret;
        }
    }

    h[n] = min;

    return h[n];

}


int main()
{
    int totalDist{};
    int n{};
    std::vector<int> vPrices{}, vDistances{};
    cost_history h;
    int x{ 1000 }, y{ 1000 };
    auto dh = std::make_unique<long long[]>(x*y);

    Input(n, vPrices, vDistances);
    totalDist = n;

    std::vector<int>::iterator it{ vDistances.begin()};
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < (n - i); k++)
        {
            dh[i*x+k] = std::accumulate(it + i, it + k + i, static_cast<long long> (*(it + i)));
            std::cout << '[' << i << ']' << '[' << k << ']' << dh[i * x + k] << std::endl;
        }
    }

    std::cout << FindCost(totalDist - 1, n-1, vPrices, vDistances, h) << std::endl;

    return 0;
}