#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXINT 1e9

using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph)
{
	vector<int> dist(graph.size(), MAXINT);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // [가중치, 목표]
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < weight)
			continue;
		for (auto& next : graph[node])
		{
			int next_node = next.first;
			int next_weight = next.second + weight;
			if (dist[next_node] > next_weight)
			{
				dist[next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}
		}
	}
	return dist;
}

int main()
{
	int N = 0, M = 0, X = 0;
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>(N + 1)); // [목표, 가중치]
	vector<vector<pair<int, int>>> graph_reverse(N + 1, vector<pair<int, int>>(N + 1)); // [목표, 가중치]
	for (int i = 0; i < M; ++i)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph_reverse[v].push_back({ u, w });
	}

	vector<int> dist_From_x = dijkstra(X, graph);
	vector<int> dist_To_x = dijkstra(X, graph_reverse);

	for (int i = 0; i < dist_From_x.size(); ++i)
		dist_From_x[i] += dist_To_x[i];

	cout << *max_element(dist_From_x.begin(), dist_From_x.end()) << endl;

	return 0;
}