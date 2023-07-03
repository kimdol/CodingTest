#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // d[n] = d[n-1] + d[n-2]
    int n;
    std::cin >> n;

    std::vector<int> d(n + 1);
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        d[i] = (d[i - 1] + d[i - 2]) % 10007;
    }

    std::cout << d[n];
}
