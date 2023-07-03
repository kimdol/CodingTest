#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

int main()
{
    long long n;    // 보석
    long long k;    // 가방
    std::cin >> n >> k;;

    std::vector<std::pair<int, int>> jewelrys(n);
    for (int i = 0; i < n; i++)
    {
        std::cin  >> jewelrys[i].first >> jewelrys[i].second;
    }

    std::vector<int> bags(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> bags[i];
    }

    /**********************핵심***************************/
    std::sort(jewelrys.begin(), jewelrys.end());
    std::sort(bags.begin(), bags.end());

    long long sum{ 0 };
    int j{};
    std::priority_queue<int> pq{};
    for (int i = 0; i < k; i++)
    {
        while (j < n && bags[i] >= jewelrys[j].first)
        {
            pq.push(jewelrys[j++].second);
        }
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    /**********************************************************/

    std::cout << sum << std::endl;
}


