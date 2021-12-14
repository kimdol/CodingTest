#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>


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
        //제일 큰 수를 제외한 n - 1개의 숫자들을 큰 순서대로 메모리에 저장
        Combination(n - 1, input, output);
        
        std::list<int> saveList = output;
        for (int i = n; i > 0; i--)
        {
            std::list<int> tmp = saveList;
            // 제일 큰 수를 사이사이에 붙이기
            for (auto& elem : tmp)
            {
                /*int k{ i };
                while (k != n)
                {
                    int digits = elem / std::pow((double)10, (double)k-1);
                    elem += (std::pow((double)10, (double)k-1) * digits);
                    k++;
                }
                elem += (std::pow((double)10, (double)n-1) * max);*/

            }
            // 합체
            // output.merge(tmp);
            output.insert(output.end(), tmp.begin(), tmp.end());
        }
    }

};

int main()
{
    CombiningFindSystem cf;
    cf.Input();
    cf.Output();
}
