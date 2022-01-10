#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int r{}, c{};
    std::cin >> r >> c;

    std::vector<int> arr(r * c);
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            std::cin >> arr[i * c + k];
        }
    }

    /*****************핵심********************/
    std::vector<std::string> ans{};
    for (int i = 0; i < r; i++)
    {
        int cnt{ 1 };
        std::string mv{};
        while (cnt++ < c)
        {
            (i % 2) ? (mv +="L") : (mv += "R");
        }
        (i == r - 1) ? (mv) : (mv += "D");


        ans.push_back(mv);
    }

    /******************************************/
    for (auto elem : ans)
    {
        std::cout << elem;
    }
    std::cout << std::endl;

}
