#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start)
{
	int n = graph.size();
	vector<int> dist(n, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int current_dist = pq.top().first;
		int current_node = pq.top().second;
		pq.pop();
		if (current_dist > dist[current_node])
			continue;
		for (pair<int, int> neighbor : graph[current_node])
		{
			int next_node = neighbor.first;
			int weight = neighbor.second;
			int new_dist = current_dist + weight;
			if (new_dist < dist[next_node])
			{
				dist[next_node] = new_dist;
				pq.push({ new_dist, next_node });
			}
		}
	}
	return dist;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

	vector<vector<pair<int, int>>> graph(N + 1);

    for (vector<int> r : road)
    {
		int u = r[0]; 
		int v = r[1];
		int w = r[2];

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

	vector<int> dist = dijkstra(graph, 1);

	for (int i = 1; i <= N; ++i)
	{
		if (dist[i] <= K)
			answer++;
	}

    return answer;
}

int main()
{
	int N = 6;
	vector<vector<int>> road = { {1,2,1} ,{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} };
	int K = 4;
	cout << solution(N, road, K) << endl;
	return 0;
}