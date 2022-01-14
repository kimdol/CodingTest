#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // a[i][0] = min(a[i-1][1], a[i-1][2]) + a[i][0]
    //d[i][0] = Min(d[i - 1][1], d[i - 1][2]) + a[i][0];
    //d[i][1] = Min(d[i - 1][0], d[i - 1][2]) + a[i][1];
    //d[i][2] = Min(d[i - 1][0], d[i - 1][1]) + a[i][2];
    int n{};
    std::cin >> n;

    int width{ 3 };
    std::vector<int> arr((n+1) * width);
    std::vector<int> cost(width);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> cost[0] >> cost[1] >> cost[2];
        arr[i * width + 0] = std::min(arr[(i - 1) * width + 1], arr[(i - 1) * width + 2]) + cost[0];
        arr[i * width + 1] = std::min(arr[(i - 1) * width + 0], arr[(i - 1) * width + 2]) + cost[1];
        arr[i * width + 2] = std::min(arr[(i - 1) * width + 0], arr[(i - 1) * width + 1]) + cost[2];
    }

    std::cout << std::min(arr[n * width + 0], std::min(arr[n * width + 1], arr[n * width + 2]));
}
