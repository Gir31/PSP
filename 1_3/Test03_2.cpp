#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph) {
	int n = graph.size();
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (cost > dist[node]) continue;
		for (pair<int, int> edge : graph[node]) {
			int next_node = edge.first;
			int next_cost = cost + edge.second;
			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				pq.push({ next_cost, next_node });
			}
		}
	}
	return dist;
}

int main()
{
	int N = 0;
	int M = 0;
	int X = 0;
	cin >> N >> M >> X;

	vector<vector<pair<int, int>>> graph(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	vector<int> dist = dijkstra(X, graph);
	int answer = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (answer < dist[i]) answer = dist[i];
	}

	cout << answer * 2;

	return 0;
}