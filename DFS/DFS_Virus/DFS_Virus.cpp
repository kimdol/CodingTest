#include<cstdio>
#include <iostream>
#include<vector>

using namespace std;

vector<vector<int>> map;
vector<bool> visit;
int computer_num, ans = 0;

void dfs(int x)
{
    ans++;
    visit[x] = true;

    for (int k = 0; k < map[x].size(); k++)
    {
        if (!visit[map[x][k]]) 
        {
            dfs(map[x][k]);
        }
    }
    return;
}

int main()
{
    int n, from, to;
    std::cin >> computer_num >> n;
    visit.resize(computer_num + 1);
    map.resize(computer_num + 1);
    for (int i = 0; i < n; i++)
    {
        std::cin >> from >> to;
        map[from].push_back(to);
        map[to].push_back(from);
    }

    dfs(1);

    printf("%d", ans - 1);
    return 0;
}

