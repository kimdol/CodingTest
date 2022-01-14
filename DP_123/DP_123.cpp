#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using cnt_history = std::map<int, int>;
int Find(int sum, cnt_history& h)
{
    if (h.count(sum) == 1)
    {
        return h[sum];
    }

    if (sum == 0)
    {
        return 1;
    }
    else if (sum < 0)
    {
        return 0;
    }


    int ret{};
    int ans{ 0 };
    for (int i = 1; i <= 3; i++)
    {
        ret = Find(sum - i, h);
        ans += ret;
    }

    h[sum] = ans;
    return h[sum];
}

int main()
{
    int n;
    std::cin >> n;

    cnt_history h;
    int sum;
    std::map<int, int> a{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> sum;
        a[sum] = Find(sum, h);
        if (sum == 0)
        {
            a[sum] = 0;
        }
        std::cout << a[sum] << std::endl;
    }
}
