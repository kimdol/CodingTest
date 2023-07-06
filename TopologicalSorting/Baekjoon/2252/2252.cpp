#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::queue<int> q;
    std::vector<std::vector<int>> v(10, std::vector<int>(10));
    int check[10]{};

    while (!q.empty())
    {
        int start = q.front();
        q.pop();

        std::cout << start << " ";
        
        for (auto e : v[start])
        {
            check[e]--;

            if (check[e] == 0)
            {
                q.push(e);
            }
        }
    }

}
