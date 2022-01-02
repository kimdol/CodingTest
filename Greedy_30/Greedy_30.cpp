#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include <string>
#include <iterator>


class CombiningFindSystem
{

private:
    std::list<char> mInput;
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
            mInput.push_back(input);
        }
    }
    void Output()
    {
        // Combination(mInput.size(), mInput, mOuput);
        Find30();
        std::cout << mResult << std::endl;
    }

private:
    void Find30()
    {
        mInput.sort(std::greater<int>());

        if (std::find(mInput.begin(), mInput.end(), '0') == mInput.end())
        {
            return;
        }
        // 숫자 다 더한 값이 3의 배수이면 참
        int sum{ 0 };
        for (auto& elem : mInput)
        {
            sum += (elem - '0');
        }
        if (sum % 3 == 0)
        {
            std::string result( mInput.begin(), mInput.end() );
            mResult = std::stoi(result);
        }

        return;
    }
    void Find()
    {
        // 30 * 1 ~ 9까지 검사 표본 준비
        for (int i = 1; i <= 9; i++)
        {
            // 생성
            // 보관
        }
        // 앞자리가 큰 순서대로 쇼트
        
        // 한뭉텅 한뭉텅 30이 나누어 떨어지는 숫자를 찾는다
        for (int i = 0; i < 10;)
        {
            // 30의 배수(샘플)의 숫자가 있는지 검사
                // 샘플 한자리 숫자를 input에 서치
                // 다음 숫자를 input에 서치

            // 검사 후 있으면 나열하고, Input에서 제외
            
            // 검사 후 없으면 다음 큰 숫자를 샘플로 두기
            i++;

        }
    }
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
                // string으로 변환
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
