#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	for(int i = 0; i < M; i++)
	{
		int u = 0, v = 0;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	vector<int> parent(N + 1, 1);
	
	for (int i = 1; i <= N; i++)
	{
		for(int node : graph[i])
		{
			parent[node] = max(parent[node], parent[i] + 1);
		}
	}

	for(int i = 1; i <= N; i++)
	{
		cout << parent[i] << " ";
	}

	return 0;
}