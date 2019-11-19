#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, v;
	cin >> n >> v;
	vector <vector <int>> g(n);
	v--;
	g[v].push_back(v + 1);
	for (auto i = 0; i < n - 2; i++)
	{
		int start, finish;
		cin >> start >> finish;
		--start; --finish;
		g[start].push_back(finish);
		g[finish].push_back(start);
	}
	
	//constexpr int inf = numeric_limits<int>::max();

	const int inf = 1e9;

	vector <int> dist(n, inf), prev(n);
	dist[v] = 0;
	queue <int> q;
	q.push(v);
	prev[0] = -1;
	while (!q.empty())
	{
		const auto u = q.front();
		q.pop();
		for (auto i : g[u])
		{
			//u -> i ребро
			if (dist[i] == inf)
			{
				prev[i] = u;
				dist[i] = dist[u] + 1;
				q.push(i);
			}
			//else if (dist[i] == prev[i])
		}
	}
}