#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kruskal(const vector<vector<pair<int, int>>>& graph, int start)
{
	vector<int> res;

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

	vector<vector<pair<int, int>>> graph(N+1);
	for (int i = 0; i < P; ++i)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	int start = 1;
	for (int i = 1; i <= N; ++i)
	{
		if (visitCost[start] > visitCost[i]) start = i;
	}



	return 0;
}