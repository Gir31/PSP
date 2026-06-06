#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	}
	sort(edges.begin(), edges.end());
	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int total_cost = 0;
	int max_edge_cost = 0;
	for (const auto& edge : edges) {
		int cost = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if (union_parent(parent, u, v)) {
			total_cost += cost;
			max_edge_cost = max(max_edge_cost, cost);
		}
	}
	cout << total_cost - max_edge_cost << endl;
	return 0;
}