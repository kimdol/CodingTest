#include <stdio.h>
#include <vector>
#include <queue>

#define INF 987654321

void print_path(int target, const std::vector<int>& prev) 
{
	std::vector<int> path;
	int current = target;

	// 경로를 역추적
	while (current != -1) {
		path.push_back(current);
		current = prev[current];
	}

	// 경로를 정방향으로 출력
	std::reverse(path.begin(), path.end());

	for (size_t i = 0; i < path.size(); ++i) {
		printf("%d", path[i]);
		if (i + 1 < path.size()) printf(" -> ");
	}
	printf("\n");
}

int main() 
{
	int n, e, k;
	int u, v, w;

	scanf_s("%d %d", &n, &e);
	scanf_s("%d", &k);

	std::vector<std::vector<std::pair<int, int>>> node(n + 1);
	std::priority_queue<
		std::pair<int, int>,
		std::vector<std::pair<int, int>>,
		std::greater<std::pair<int, int>>> pq;

	std::vector<int> value(n + 1, INF);
	std::vector<int> prev(n + 1, -1);

	for (int i = 0; i < e; i++) 
	{
		scanf_s("%d %d %d", &u, &v, &w);
		node[u].push_back(std::make_pair(v, w));
	}


	value[k] = 0;
	pq.push(std:: make_pair(0, k));


	while (!pq.empty()) 
	{
		int x = pq.top().first;
		int U = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[U].size(); i++) 
		{
			int V = node[U][i].first;
			int W = node[U][i].second;

			if (x + W < value[V]) 
			{
				value[V] = x + W;
				prev[V] = U; // 경로 추적용 추가
				pq.push(std::make_pair(x + W, V));
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (value[i] == INF)
		{
			printf("INF\n");
		}
		else
		{
			printf("노드 %d까지 거리: %d\n", i, value[i]);
			printf("경로: ");
			print_path(i, prev); // 경로 출력
		}
	}


	return 0;
}
