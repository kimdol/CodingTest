#include <iostream>
#include<algorithm>
#include<vector>

class ATM
{
public:
    class Withdraw
    {
    public:
        int num;
        int delay;

    public:
        Withdraw(int _num, int _delay)
            : num{ _num }, delay{ _delay }
        {}
        bool operator<(Withdraw w) const
        {
            return delay < w.delay;
        };
    };
private:
    int mHumanNum;
    std::vector<Withdraw> mvWithdraw;
public:
    ATM()
        : mHumanNum{}, mvWithdraw{}
    {

    }
    ~ATM()
    {

    }

public:
    void Input()
    {
        std::cin >> mHumanNum;
        for (int i = 0; i < mHumanNum; i++)
        {
            int d;
            std::cin >> d;
            mvWithdraw.push_back(Withdraw(i, d));
        }
        
    }
    void Output()
    {
        std::cout << DelayMinSum() << std::endl;
    }

public:
    void Sort()
    {
        std::sort(mvWithdraw.begin(), mvWithdraw.end());
    }
    // sort 작동 확인용
    void Prt()
    {
        std::cout << mHumanNum << std::endl;

        for (auto& var : mvWithdraw)
        {
            std::cout << var.num
                << " : "
                << var.delay
                << " || ";
        }

        std::cout << std::endl;
    }

private:
    int DelayMinSum()
    {
        int result{ 0 };
        for (int i = 0; i < mHumanNum; i++)
        {
            int sum{ 0 };
            for (int k = 0; k < (i + 1); k++)
            {
                sum += mvWithdraw[k].delay;
            }
            result += sum;
        }
        return result;
    }
};

int main()
{
    ATM atm;
    atm.Input();
    atm.Sort();
    atm.Output();
}
