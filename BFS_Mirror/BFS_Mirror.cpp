#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, mirr_num = 0, ans = 9999999;
char map[50][50];
int visited[50][50][4];

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

struct COORD
{
    int y, x;
    int time;
    int dir;
};

pair<int, int> reflect_dir(int cur_dir)
{
    if (cur_dir <= 1) // from east, west
    {
        return make_pair(2, 3);
    }
    else // from north, south
    {
        return make_pair(0, 1);
    }
}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }

    COORD s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '#')
            {
                s.y = i;
                s.x = j;
            }

            for (int dir = 0; dir < 4; dir++)
            {
                visited[i][j][dir] = 9999999;
            }
        }
    }

    std::queue<COORD> q;
    s.time = 0;
    for (int i = 0; i < 4; i++)
    {
        s.dir = i;
        q.push(s);
    }

    map[s.y][s.x] = '*'; // to prevent returning to starting place

    while (!q.empty())
    {
        COORD cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x][cur.dir] <= cur.time)
        {
            continue;
        }
        visited[cur.y][cur.x][cur.dir] = cur.time;

        // advance
        COORD next;
        next.y = cur.y + dy[cur.dir];
        next.x = cur.x + dx[cur.dir];
        next.time = cur.time;

        // '*' or out of boundary
        if (map[next.y][next.x] == '*' ||
            next.x < 0 ||
            next.y < 0 ||
            next.x >= n ||
            next.y >= n)
        {
            continue;
        }

        if (map[next.y][next.x] == '!') // '!'
        {
            next.dir = cur.dir;
            q.push(next);

            next.time++;
            pair<int, int> new_dir = reflect_dir(cur.dir);

            next.dir = new_dir.first;
            q.push(next);
            next.dir = new_dir.second;
            q.push(next);
        }
        else if (map[next.y][next.x] == '.')
        {
            next.dir = cur.dir;
            q.push(next);
        }
        else if (map[next.y][next.x] == '#')
        {
            ans = min(ans, (int)next.time);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
