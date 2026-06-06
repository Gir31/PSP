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
	int N = 0;
	cin >> N;
	cin.ignore();

	vector<vector<int>> graph(N + 1);
	vector<int> time(N + 1, 0);
	vector<int> result(N + 1, 0);
	vector<int> parent(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> time[i] >> parent[i];

		for(int j = 0; j < parent[i]; j++)
		{
			int leadOrder = 0;
			cin >> leadOrder;
			graph[leadOrder].push_back(i);
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (parent[i] == 0) result[i] = time[i];
	}

	vector<int> order = topologySort(graph, parent);

	for(int o : order)
	{
		for(int next : graph[o])
		{
			result[next] = max(result[next], result[o] + time[next]);
		}
	}
	
	cout << *max_element(result.begin(), result.end());

	return 0;
}