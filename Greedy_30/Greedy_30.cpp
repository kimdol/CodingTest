#include <iostream>
#include <list>
#include <algorithm>


class CombiningFindSystem
{

private:
    std::list<int> mInput;
    std::list<int> mOuput;
    int mResult;

public:
    CombiningFindSystem()
        : mInput{}, mResult { 0 }
    {}

public:
    void Input()
    {
        while (1)
        {
            char input;
            std::cin.get(input);
            if (input == '\n')
            {
                break;
            }
            mInput.push_back(static_cast<int>(input - 48));
        }
    }
    void Output()
    {
        Combination(mInput.size(), mInput, mOuput);
    }

private:
    void Combination(int n, std::list<int> input, std::list<int>& output)
    {
        input.sort(std::greater<int>());
        int max = *(input.begin());
        input.pop_front();
        std::cout << max;

        Combination(n - 1, input, output);

        std::list<int> tmp = output;
        for (int i = 0; i < n + 1; i++)
        {
            

        }

    }

};

int main()
{
    CombiningFindSystem cf;
    cf.Input();
    cf.Output();
}
