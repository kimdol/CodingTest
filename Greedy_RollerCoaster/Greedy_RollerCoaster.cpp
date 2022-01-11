#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int r{}, c{}, mr{ -1 }, mc{ -1 }, min{ 10000000 };
    std::cin >> r >> c;

    std::vector<int> arr(r * c);
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < c; k++)
        {
            std::cin >> arr[i * c + k];
            if ((!(r % 2) && !(c % 2)) 
                && (i + k) % 2 
                && arr[i * c + k] < min)
            {
                mr = i;
                mc = k;
                min = arr[i * c + k];
            }
        }
    }

    /*****************핵심********************/
    std::vector<std::string> ans{};
    int j{};
    (r % 2) ? j = r : j = c;    // j = r : 가로부터, j = c : 세로부터
    int cntMax{};
    (r % 2) ? cntMax = c : cntMax = r;
    (mc != -1) ? j = r : j; // 짝수 x 짝수라면
    int mvpth{};
    double m{}, n{ 0.5 };
    for (int i = 0; i < j; i++)
    {
        int cnt{ 1 };
        std::string mv{};

        ((i == mr) || (1 == mr) || ((i == j - 2) && (i + 1 == mr))) ?
            cntMax = 2 * c : (j == r) ? cntMax = c : cntMax = r;
        
        while (cnt++ < cntMax)
        {
            if ((i == mr) || (1 == mr) || ((i == j - 2) && (i + 1 == mr)))
            {
                if (std::trunc(n) == mc)
                {
                    cnt += 2;
                    n = -10000000.0;        // n을 없애기
                    (i % 2) ? (mv += "L") : (mv += "R");
                    if (cnt >= cntMax)
                    {
                        break;
                    }
                }
                (mvpth == 0) ? (mv += "D") : mv;
                (mvpth == 1) ? (i % 2) ? (mv += "L") : (mv += "R") : mv;
                (mvpth == 2) ? (mv += "U") : mv;
                (mvpth == 3) ? (i % 2) ? (mv += "L") : (mv += "R") : mv;
                (mvpth == 3) ? mvpth = 0 : mvpth++;
                n += 0.5;
            }
            else if (j == r)
            {
                (n < 0.0) ?
                    (i % 2) ? (mv += "R") : (mv += "L") :
                    (i % 2) ? (mv += "L") : (mv += "R");
            }
            else if (j == c)
            {
                (i % 2) ? (mv += "U") : (mv += "D");
            }
        }
        ((i == mr) || (1 == mr) || ((i == j - 2) && (i + 1 == mr))) ? i++ : i;
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