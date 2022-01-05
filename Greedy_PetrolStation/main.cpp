#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <array>

void Input(int& n, std::vector<int>& prices, std::vector<int>& distances)
{
    std::cin >> n;

    distances.resize(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> distances[i];
    }

    prices.resize(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> prices[i];
    }

}

using cost_history = std::map<long long, long long>;
long long FindCost(const int& total, int n, const std::vector<int>& prices, const std::vector<int>& distances, cost_history& h)
{
    if (prices[total - n] == 1)
    {
        h[n] = std::accumulate(distances.begin() + (total - n), distances.end(), 0LL);
        return h[n];
    }

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

    Input(n, vPrices, vDistances);
    totalDist = n;

    auto dsp = std::make_shared<std::array<std::vector<long long>, 100000>>();
    // long long a = ((*dsp)[3])[0];

    for (int i = 0; i < n - 1; i++)
    {
        std::partial_sum(vDistances.begin() + i, vDistances.end(), ((*dsp)[i]).begin());
    }

    std::cout << FindCost(totalDist - 1, n-1, vPrices, vDistances, h) << std::endl;

    return 0;
}
/*
long long UpFindCost(long long cnt, long long sum, const std::vector<int>& prices, const std::vector<int>& distances, cost_history& h)
{
    if (prices[cnt] == 1)
    {
        h[sum] = std::accumulate(distances.begin() + cnt, distances.end(), 0LL);
        return h[sum];
    }

    if (h.count(sum) == 1)
    {
        return h[sum];
    }

    if (cnt == distances.size())
    {
        h[sum] = sum;
        return h[sum];
    }

    long long ret{};
    long long min{ 1000000000000 };
    std::vector<long long> distSum(distances.size());
    std::partial_sum(distances.begin() + cnt, distances.end(), distSum.begin());
    for (long long i = cnt; i < distances.size(); i++)
    {
        ret = UpFindCost(i + 1, sum + (distSum[i - cnt] * prices[cnt]), prices, distances, h);
        if (i == 0 || ret < min)
        {
            min = ret;
        }
    }

    h[sum] = min;
    return h[sum];
}
*/

/*
    // 스트림 분석
    std::cin >> n;
    std::cin.ignore(INT_MAX, '\n');
    std::cin >> prices;
    std::cin >> distances;

* 스트림 분석
std::istream& operator >> (std::istream& is, std::vector<int>& v)
{

   while (1)
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

    int input;

    is >> input;

    v.push_back(input);

    return is;
}
*/
/*
* accumulate 실험
int x{ 1000 }, y{ 1000 };
auto dh = std::make_unique<long long[]>(x*y);
std::vector<int>::iterator it{ vDistances.begin() };
for (int i = 0; i < (n - 1); i++)
{
    for (int k = 0; k < ((n - 1) - i); k++)
    {
       // std::vector<int> tmp{ vDistances.begin() + 2, vDistances.begin() + 2 };
       // dh[i*x+k] = std::accumulate(it + i, it + k + i, static_cast<long long>(vDistances[i]));
        for (int j = 0; j < k; j++)
        {

        }
        std::cout << '[' << i << ']' << '[' << k << ']' << dh[i * x + k] << std::endl;
    }
}
*/