#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> topologySort(vector<vector<int>>& graph, vector<int>& parent)
{
	vector<int> result;
	queue<int> q;

	for (int i = 1; i < parent.size(); i++)
		if (parent[i] == 0) q.push(i);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		result.push_back(node);

		for (int next : graph[node])
		{
			parent[next]--;
			if (parent[next] == 0) q.push(next);
		}
	}

	return result;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> cow(N + 1);
	vector<int> result(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> cow[i];
	}

	vector<vector<int>> order(N +1);
	vector<int> parent(N + 1, 0);
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		order[u].push_back(v);
		parent[v]++;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (parent[i] == 0) result[i] = cow[i];
	}

	vector<int> ts = topologySort(order, parent);

	for (int i : ts)
	{
		for (int next : order[i])
		{
			result[next] = max(result[next], result[i] + cow[next]);
		}
	}

	cout << *max_element(result.begin(), result.end());

	return 0;
}