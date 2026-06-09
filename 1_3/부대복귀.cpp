#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(const vector<vector<int>>& graph, int n, int start)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curr_node = pq.top().second;
        int curr_cost = pq.top().first;
        pq.pop();
        if (dist[curr_node] < curr_cost) continue;
        for (int next_node : graph[curr_node])
        {
            int next_cost = curr_cost + 1;
            if (dist[next_node] > next_cost)
            {
                dist[next_node] = next_cost;
                pq.push({ next_cost, next_node });
            }
        }
    }

    return dist;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<vector<int>> graph(n + 1);
    for (vector<int> road : roads)
    {
        int u = road[0]; int v = road[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> dist = dijkstra(graph, n, destination);
    for (int source : sources)
    {
        if (dist[source] == INF) answer.push_back(-1);
        else answer.push_back(dist[source]);
    }

    return answer;
}