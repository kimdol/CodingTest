#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 51

int N, M;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 ,0 };
int arr[MAX][MAX] = { 0, };
int sum[MAX][MAX] = { 0, };
int max_num = 0;
bool visit[MAX][MAX] = { false, };

void BFS(int init_x, int init_y) {
	visit[init_x][init_y] = true;
	queue <pair<int, int>> que;
	que.push(make_pair(init_x, init_y));

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (arr[nx][ny] == 1 && !visit[nx][ny]) {
				visit[nx][ny] = true;
				sum[nx][ny] = sum[x][y] + 1;
				max_num = max(max_num, sum[nx][ny]);
				que.push(make_pair(nx, ny));
			}
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	void();
	cin >> N >> M;

	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			if (temp == 'L')
			{
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				BFS(i, j);
				memset(visit, false, sizeof(visit));
				memset(sum, 0, sizeof(sum));
			}
		}
	}

	cout << max_num;
	return 0;
}
