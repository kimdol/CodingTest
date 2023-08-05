#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N, M;
    std::cin >> N >> M;


    std::queue<int> q;
    std::vector<std::vector<int>> node(N + 1);
    std::vector<int> entry(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int a, b; 
        std::cin >> a >> b;
        entry[b]++;
        node[a].push_back(b);
    }


    for (int i = 1; i <= N; i++)
    {
        if (entry[i] == 0)
        {
            q.push(i);
        }
    }


    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        std::cout << cur << " ";
        
        for (auto e : node[cur])
        {
            entry[e]--;

            if (entry[e] == 0)
            {
                q.push(e);
            }
        }
    }

    std::cout << std::endl;

}
