#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using min_history = std::map<int, int>;
int FindMin(int n, min_history& h)
{
	if (n == 1)
	{
		return 0;
	}

	if (n < 1)
	{
		return 1;
	}

	if (h.count(n) == 1)
	{
		return h[n];
	}

	h[n] = FindMin(n - 1, h) + 1;

	if (!(n % 2))
	{
		int tmp{ FindMin(n / 2, h) + 1 };
		if (h[n] > tmp)
		{
			h[n] = tmp;
		}
	}

	if (!(n % 3))
	{
		int tmp{ FindMin(n / 3, h) + 1 };
		if (h[n] > tmp)
		{
			h[n] = tmp;
		}
	}

	return h[n];
}
int main()
{
	//1번 규칙 (3으로 나누어 떨어진다) : D[N] = D[N/3] + 1
	//2번 규칙(2로 나누어 떨어진다) : D[N] = D[N / 2] + 1
	//3번 규칙(1 을 뺀다) : D[N] = D[N - 1] + 1
	int n;
	min_history h;
	std::cin >> n;

	std::vector<int> d(n+1);
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
		{
			d[i] = std::min(d[i / 2] + 1, d[i]);
		}
		if (i % 3 == 0)
		{
			d[i] = std::min(d[i / 3] + 1, d[i]);
		}
	}

	std::cout << d[n];
	
}
