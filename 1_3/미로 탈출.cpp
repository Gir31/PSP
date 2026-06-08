#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

struct STATE {
    int node; 
    int cost;  
    int trapState; 

    bool operator>(const STATE& other) const {
        return cost > other.cost;
    }
};

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    map<int, int> trapIdx;
    for (int i = 0; i < traps.size(); i++) {
        trapIdx[traps[i]] = i;
    }

    vector<vector<vector<int>>> adj(n + 1);
    for (auto& r : roads) {
        int u = r[0], v = r[1], w = r[2];
        adj[u].push_back({ v, w, 0 }); 
        adj[v].push_back({ u, w, 1 }); 
    }

    const int INF = 1e9;

    int numStates = 1 << traps.size(); 
    vector<vector<int>> dist(n + 1, vector<int>(numStates, INF));

    priority_queue<STATE, vector<STATE>, greater<STATE>> pq;

    pq.push({ start, 0, 0 });
    dist[start][0] = 0;

    while (!pq.empty()) {
        int curr_node = pq.top().node;
        int curr_cost = pq.top().cost;
        int curr_state = pq.top().trapState;
        pq.pop();

        if (curr_node == end) return curr_cost;

        if (curr_cost > dist[curr_node][curr_state]) continue;

        bool is_curr_trap_on = false;
        if (trapIdx.count(curr_node)) {
            int idx = trapIdx[curr_node];
            if ((curr_state & (1 << idx)) != 0) {
                is_curr_trap_on = true;
            }
        }

        for (auto& edge : adj[curr_node]) {
            int next_node = edge[0];
            int weight = edge[1];
            int is_reverse = edge[2];
            bool is_next_trap_on = false;
            if (trapIdx.count(next_node)) {
                int idx = trapIdx[next_node];
                if ((curr_state & (1 << idx)) != 0) {
                    is_next_trap_on = true;
                }
            }

            bool is_flipped = (is_curr_trap_on != is_next_trap_on);

            if (is_flipped != is_reverse) continue;

            int next_state = curr_state;
            if (trapIdx.count(next_node)) {
                int idx = trapIdx[next_node];
                next_state ^= (1 << idx);
            }

            if (curr_cost + weight < dist[next_node][next_state]) {
                dist[next_node][next_state] = curr_cost + weight;
                pq.push({ next_node, curr_cost + weight, next_state });
            }
        }
    }

    return -1;
}