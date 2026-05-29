#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int V, E;

vector<vector<int>> graph;
vector<int> previous_node;

int dijkstra() {
    vector<int> D(V, INF);
    D[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (D[curr] < dist) continue;

        for (int next_node = 0; next_node < V; ++next_node) {
            int weight = graph[curr][next_node];
            if (weight == INF) continue;

            if (dist + weight < D[next_node]) {
                D[next_node] = dist + weight;
                pq.push({ D[next_node], next_node });
                previous_node[next_node] = curr;
            }
        }
    }
    return D[V - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> V >> E)) return 0;

    graph.assign(V, vector<int>(V, INF));
    previous_node.assign(V, -1);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    int original = dijkstra();

    vector<int> path;
    int curr = V - 1;
    while (curr != -1) {
        path.push_back(curr);
        curr = previous_node[curr];
    }
    reverse(path.begin(), path.end());

    int most_double = original;

    for (size_t i = 0; i < path.size() - 1; ++i) {
        int u = path[i];
        int v = path[i + 1];

        graph[u][v] *= 2;
        graph[v][u] *= 2;

        most_double = max(most_double, dijkstra());

        graph[u][v] /= 2;
        graph[v][u] /= 2;
    }

    cout << most_double - original << "\n";

    return 0;
}