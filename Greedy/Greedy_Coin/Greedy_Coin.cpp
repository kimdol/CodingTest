#include <iostream>
#include <algorithm>
#include <functional>

class CoinSystem
{

private:
    int N, K;
    int Ai[10];
    int mResult;

public:
    CoinSystem()
        : N{}, K{}, Ai{}, mResult{}
    {

    }
    void Input()
    {
        std::cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            std::cin >> Ai[i];
        }
    }
    void Output()
    {
        Calculator();
        std::cout << mResult;
    }

private:
    void Calculator()
    {
        int tmpAi[10];
        std::copy(Ai, Ai + 10, tmpAi);
        std::sort(tmpAi, tmpAi + 10, std::greater<int>());

        int rest{ K };
        int i{ 0 };
        // 나머지가 0이하가 될 때까지 지속
        while (rest > 0)
        {
            // 제일 높은 수를 무작정 나눔
            mResult += (rest / tmpAi[i]);
            
            rest %= tmpAi[i++];
        }
    }
};
int main()
{
    CoinSystem cs;

    cs.Input();
    cs.Output();
}
