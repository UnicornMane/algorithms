#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

void dijkstra(int start, vector <int>& dist, vector <int>& prev, vector <vector <pair<int, int>>>& g, set <pair<int, int>>& s)
{
	dist[start] = 0;
	s.insert({ 0, start });
	while (!s.empty())
	{
		int u = s.begin()->second;
		s.erase(s.begin());
		for (auto c : g[u])
		{
			if (dist[u] + c.second < dist[c.first])
			{
				s.erase({ dist[c.first], c.first });
				dist[c.first] = dist[u] + c.second;
				s.insert({ dist[c.first], c.first });
				prev[c.first] = u;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	const int INF = 1e9;
	vector <int> dist(n, INF), prev(n, -1), prise(n);
	vector <vector <pair<int, int>>> g(m);
	
	for (int i = 0; i < n; i++)
	{
		cin >> prise[i];
	}
	set<pair<int, int>> s;

	for (int i = 0; i < m; i++)
	{
		int start, finish;
		cin >> start >> finish;
		--start; --finish;
		
		if (prise[start] == prise[finish])
		{
			g[start].push_back({ finish, 1 });
			g[finish].push_back({start, 1});
		}
		else
		{
			g[start].push_back({ finish, 3 });
			g[finish].push_back({ start, 3 });
		}
	}

	dijkstra(0, dist, prev, g, s);

	vector <int> ans;
	if (dist[n - 1] == INF)
	{
		cout << "impossible";
		return 0;
	}
	

		ans.push_back(n - 1);
		int t = prev[n - 1];
		while(t != -1)
		{
			ans.push_back(t);
			t = prev[t];
		}
	

	reverse(ans.begin(), ans.end());
	int cost = 0;
	
	for (int i = 0; i < ans.size() - 1; i++)
	{
		if (prise[ans[i]] != prise[ans[i + 1]])
		{
			cost++;
		}
	}
	cout << cost << " " << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] + 1 << " ";
	}
}