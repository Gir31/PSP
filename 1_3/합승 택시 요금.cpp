#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph)
{
	vector<int> dist(graph.size(), 1e9);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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

vector<vector<int>> Floyd_Warshall(vector<vector<pair<int, int>>>& graph)
{
	int n = graph.size();
	vector<vector<int>> dist(n, vector<int>(n, 1e9));
	for (int i = 0; i < n; ++i)
		dist[i][i] = 0;

	for (int i = 0; i < n; ++i)
		for (const auto& next : graph[i])
			dist[i][next.first] = next.second;

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

	vector<vector<pair<int, int>>> graph(n + 1);
	for (vector<int> fare : fares) {
		graph[fare[0]].push_back({ fare[1], fare[2] });
		graph[fare[1]].push_back({ fare[0], fare[2] });
	}

	///////////////////////////////////////////////////////////////
	// Floyd-Warshall 풀이법
	vector<vector<int>> Floyd_Warshall_dist = Floyd_Warshall(graph);
	int min_cost_Floyd_Warshall = 1e9;
	for (int k = 1; k <= n; ++k)
	{
		min_cost_Floyd_Warshall = min(min_cost_Floyd_Warshall, Floyd_Warshall_dist[s][k] + Floyd_Warshall_dist[k][a] + Floyd_Warshall_dist[k][b]);
	}

	///////////////////////////////////////////////////////////////
	// Dijkstra 풀이법
	vector<int> dist_From_s = dijkstra(s, graph);
	vector<int> dist_From_a = dijkstra(a, graph);
	vector<int> dist_From_b = dijkstra(b, graph);

	int min_cost = 1e9;
	for (int i = 1; i <= n; ++i) 
	{
		if (dist_From_s[i] == 1e9 || dist_From_a[i] == 1e9 || dist_From_b[i] == 1e9)
			continue;
		int cost = dist_From_s[i] + dist_From_a[i] + dist_From_b[i];

		if (cost < min_cost)
			min_cost = cost;
	}

	answer = min_cost;

    return answer;
}

int main()
{
	int n = 6, s = 4, a = 5, b = 6;
	vector<vector<int>> fares = 
		{{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}};
	cout << solution(n, s, a, b, fares) << endl;
	return 0;
}