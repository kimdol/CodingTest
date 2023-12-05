#include <stdio.h>
#include <vector>
#include <queue>

#define INF 987654321

int main() 
{
	int n, e, k;
	int u, v, w;

	scanf("%d %d", &n, &e);
	scanf("%d", &k);

	std::vector<std::vector<std::pair<int, int>>> node(n + 1);
	std::priority_queue<
		std::pair<int, int>,
		std::vector<std::pair<int, int>>,
		std::greater<std::pair<int, int>>> pq;
	std::vector<int> value(n + 1, INF);

	for (int i = 0; i < e; i++) 
	{
		scanf("%d %d %d", &u, &v, &w);
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
			printf("%d\n", value[i]);
		}
	}


	return 0;
}
