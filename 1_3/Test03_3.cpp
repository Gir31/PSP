#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int find_parent(vector<int>& parent, int x) {
	while (x != parent[x]) {
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

bool union_parent(vector<int>& parent, int a, int b) {
	a = find_parent(parent, a);
	b = find_parent(parent, b);
	if (a != b) {
		parent[b] = a;
		return true;
	}
	return false;
}

int kruskal(const vector<pair<int, pair<int, int>>>& graph, int n)
{
	int res = 0;

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	for (const pair<int, pair<int, int>>& edge : graph)
	{
		pq.push({ edge.first ,{edge.second.first, edge.second.second} });
	}

	vector<int> parent(n + 1);
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();
		if (union_parent(parent, u, v))
		{
			res += cost;
		}
	}

	return res;
}

int main()
{
	int N = 0;
	int P = 0;
	cin >> N >> P;

	vector<int> visitCost(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> visitCost[i];
	}

	vector<pair<int, pair<int, int>>> graph;
	for (int i = 0; i < P; ++i)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;

		int totalCost = (2 * w) + (visitCost[u] + visitCost[v]);

		graph.push_back({ totalCost, {v, u} });
	}

	int minCost = 1e9;
	for (int i = 1; i <= N; ++i)
	{
		if (minCost > visitCost[i]) minCost = visitCost[i];
	}

	int res = kruskal(graph, N) + minCost;

	cout << res;

	return 0;
}