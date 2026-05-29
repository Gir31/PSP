#include <string>
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

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

	vector<vector<pair<int, int>>> graph(n + 1);

	for (vector<int> e : edge) {
		graph[e[0]].push_back({e[1], 1});
		graph[e[1]].push_back({e[0], 1});
	}

	vector<int> dist = dijkstra(1, graph);

	int max_dist = 0;

	for (int i = 1; i <= n; i++) {
		max_dist = max(max_dist, dist[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == max_dist) {
			answer++;
		}
	}

    return answer;
}