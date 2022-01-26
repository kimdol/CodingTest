#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<bool> vi{};
std::vector<std::string> arr{};
std::vector<int> dxdy(4);
std::vector<int> ans{};
int ansCnt{};

bool IsInside(int ny, int nx)
{
    return (0 <= nx && N > nx && 0 <= ny && N > ny);
}

void DFS(int n)
{
    vi[n] = true;
    ans[ansCnt - 1]++;

    for (int i = 0; i < 4; i++)
    {
        int newN = n + dxdy[i];
        if (IsInside(newN/N, newN%N) && !vi[newN] && arr[newN / N][newN % N] == '1')
        {
            DFS(newN);
        }
    }
}

int main()
{
    // 입력받기
    std::cin >> N;
    dxdy[0] = -1; dxdy[1] = 1;
    dxdy[2] = -1 * N; dxdy[3] = N;
    vi.resize(N * N);
    arr.resize(N);
    // 입력받기
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
    // 처리
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            int newN = i * N + k;
            if (arr[i][k] == '1' && !vi[newN])
            {
                ans.resize(++ansCnt);
                std::fill(vi.begin(), vi.end(), false);
                DFS(newN);
            }
        }
    }
    // 출력
    std::cout << ans.size() << std::endl;
    for (auto e : ans)
    {
        std::cout << e << std::endl;
    }
    

}
