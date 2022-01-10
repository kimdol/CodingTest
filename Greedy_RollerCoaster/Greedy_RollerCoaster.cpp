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
    int j{};
    (r % 2) ? j = r : j = c;    // j = r : 가로부터, j = c : 세로부터
    int cntMax{};
    (r % 2) ? cntMax = c : cntMax = r;
    for (int i = 0; i < j; i++)
    {
        int cnt{ 1 };
        std::string mv{};
        while (cnt++ < cntMax)
        {
            if (j == r)
            {
                (i % 2) ? (mv += "L") : (mv += "R");
            }
            else if (j == c)
            {
                (i % 2) ? (mv += "U") : (mv += "D");
            }
            
        }
        (i == j - 1) ? (mv) : ((j == r) ? (mv += "D") : (mv += "R"));


        ans.push_back(mv);
    }

    /******************************************/
    for (auto elem : ans)
    {
        std::cout << elem;
    }
    std::cout << std::endl;

}
