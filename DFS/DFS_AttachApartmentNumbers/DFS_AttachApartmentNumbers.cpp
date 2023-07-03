#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<bool> vi{};
std::vector<std::string> arr{};
std::vector<int> dy{ 0, 0, -1, 1 };
std::vector<int> dx{ -1, 1, 0, 0 };
std::vector<int> ans{};
int ansCnt{};

bool IsInside(int ny, int nx)
{
    return (0 <= nx && N > nx && 0 <= ny && N > ny);
}

void DFS(int m, int n)
{
    vi[m * N + n] = true;
    ans[ansCnt - 1]++;

    for (int i = 0; i < 4; i++)
    {
        int ny = m + dy[i];
        int nx = n + dx[i];
        if (IsInside(ny, nx) && !vi[ny * N + nx] && arr[ny][nx] == '1')
        {
            DFS(ny, nx);
        }
    }
}

int main()
{
    // 입력받기
    std::cin >> N;
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
                DFS(i, k);
            }
        }
    }
    // 출력
    std::cout << ans.size() << std::endl;
    std::sort(ans.begin(), ans.end());
    for (auto e : ans)
    {
        std::cout << e << std::endl;
    }
    

}
