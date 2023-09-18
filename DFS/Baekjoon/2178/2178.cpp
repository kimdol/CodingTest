#include <iostream>
using namespace std;

/*

4 6
101111
101010
101011
111011


15

*/

int N, M;
char Map[101][101]; // 맵
int Visit[101][101]; // 방문 표시
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int Min = 10001;

void DFS(int x, int y, int depth)
{
	if (x < 0 || y < 0 || x >= N || y >= M)
	{
		return;
	}

	if (x == N - 1 && y == M - 1)
	{
		if (depth < Min)
		{
			Min = depth;
		}

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (Visit[nx][ny] == 0 && Map[nx][ny] == '1')
		{
			Visit[nx][ny] = 1;
			DFS(nx, ny, depth + 1);
			Visit[nx][ny] = 0;
		}
	}

}

int main(void)
{
	std::cin >> N >> M;        // N세로 M가로

	for (int i = 0; i < N; i++)
	{
		std::cin >> Map[i];
	}

	Visit[0][0] = 1;
	DFS(0, 0, 1);

	std::cout << Min << std::endl;
}
