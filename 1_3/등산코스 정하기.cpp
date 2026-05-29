#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto& path : paths) {
        int u = path[0], v = path[1], w = path[2];
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    vector<bool> is_summit(n + 1, false);
    for (int s : summits) {
        is_summit[s] = true;
    }

    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int gate : gates) {
        dist[gate] = 0;
        pq.push({ 0, gate });
    }

    while (!pq.empty()) {
        int intensity = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < intensity) continue;

        if (is_summit[curr]) continue;

        for (auto& edge : graph[curr]) {
            int next_node = edge.first;
            int weight = edge.second;

            int next_intensity = max(intensity, weight);

            if (next_intensity < dist[next_node]) {
                dist[next_node] = next_intensity;
                pq.push({ next_intensity, next_node });
            }
        }
    }

    int min_summit = -1;
    int min_intensity = INF;

    sort(summits.begin(), summits.end());

    for (int s : summits) {
        if (dist[s] < min_intensity) {
            min_intensity = dist[s];
            min_summit = s;
        }
    }

    return { min_summit, min_intensity };
}

int main() {
	solution(6, { {1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1} }, { 1, 3 }, { 5 });
	return 0;
}