#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to, id;
    long long w, l;
};

vector<long long> dijkstra(int start, int n, const vector<vector<Edge>>& graph) {
    vector<long long> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        long long cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (cost > dist[curr]) continue;

        for (const Edge& e : graph[curr]) {
            long long next_cost = cost + e.w;
            if (dist[e.to] > next_cost) {
                dist[e.to] = next_cost;
                pq.push({ next_cost, e.to });
            }
        }
    }
    return dist;
}

vector<int> solution(int n, vector<vector<int>> roads) {
    vector<int> answer;
    int m = roads.size();

    vector<vector<Edge>> graph(n + 1);
    vector<vector<Edge>> graph_rev(n + 1);

    for (int i = 0; i < m; i++) {
        int u = roads[i][0], v = roads[i][1];
        long long l = roads[i][2], t = roads[i][3];
        long long w = l + t;

        graph[u].push_back({ v, i + 1, w, l });
        graph[v].push_back({ u, i + 1, w, l });
        graph_rev[v].push_back({ u, i + 1, w, l });
        graph_rev[u].push_back({ v, i + 1, w, l });
    }

    vector<long long> from_1 = dijkstra(1, n, graph);
    vector<long long> to_N = dijkstra(n, n, graph_rev);
    long long origin = from_1[n];

    vector<int> in_count(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u = roads[i][0], v = roads[i][1];
        long long w = roads[i][2] + roads[i][3];

        if (from_1[u] + w + to_N[v] == origin) in_count[v]++;
        if (from_1[v] + w + to_N[u] == origin) in_count[u]++;
    }

    for (int i = 0; i < m; i++) {
        int u = roads[i][0], v = roads[i][1];
        long long l = roads[i][2], t = roads[i][3];
        long long w = l + t;

        bool on_path_uv = (from_1[u] + w + to_N[v] == origin);
        bool on_path_vu = (from_1[v] + w + to_N[u] == origin);

        if (on_path_uv || on_path_vu) {
            if (t > 0) {
                answer.push_back(i + 1);
                continue;
            }
            bool critical = (on_path_uv && in_count[v] == 1) ||
                (on_path_vu && in_count[u] == 1);
            if (critical) {
                answer.push_back(i + 1);
            }
        }
        else {
            long long potential = min(from_1[u] + l + to_N[v],
                from_1[v] + l + to_N[u]);
            if (potential < origin) {
                answer.push_back(i + 1);
            }
        }
    }

    if (answer.empty()) return { -1 };
    return answer;
}