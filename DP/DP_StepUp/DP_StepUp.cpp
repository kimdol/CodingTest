#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // a[4][한칸] = 4번째 계단 코스트 + a[3][두칸]
    // a[4][두칸] = 4번째 계단 코스트 + max(a[2][한칸], a[2][두칸])
    int n;
    std::cin >> n;

    std::vector<int> a((n + 3) * 2);
    std::vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> cost[i];
    }

    a[1 * 2 + 0] = cost[0];
    a[1 * 2 + 1] = cost[0];

    for (int i = 2; i <= n; i++)
    {
        a[i * 2 + 0] = cost[i - 1] + a[(i - 1) * 2 + 1];
        a[i * 2 + 1] = cost[i - 1] + std::max(a[(i - 2) * 2 + 0], a[(i - 2) * 2 + 1]);
    }

    std::cout << std::max(a[n * 2 + 0], a[n * 2 + 1]);
}
