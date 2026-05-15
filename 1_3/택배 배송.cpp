#include <iostream>
#include <vector>
#include <queue>

#define MAXINT 1e9

using namespace std;

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<pair<int, int>>> graph(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(N + 1, MAXINT);
	dist[1] = 0;

	pq.push({ 0, 1 });

	while (!pq.empty())
	{
		int node = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		if (dist[node] < distance) continue;

		for (auto& edge : graph[node])
		{
			int next_node = edge.first;
			int weight = edge.second;

			if (dist[next_node] > dist[node] + weight)
			{
				dist[next_node] = dist[node] + weight;
				pq.push({ dist[next_node], next_node });
			}
		}
	}

	cout << dist.back() << endl;

	return 0;
}