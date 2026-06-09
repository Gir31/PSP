#include <vector>
#include <queue>

using namespace std;

vector<int> graph[200005];
int before_room[200005]; 
int after_room[200005];
bool is_visited[200005];
bool hang_over[200005];

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for (const auto& p : path) {
        graph[p[0]].push_back(p[1]);
        graph[p[1]].push_back(p[0]);
    }

    for (const auto& o : order) {
        before_room[o[1]] = o[0];
        after_room[o[0]] = o[1];
    }

    if (before_room[0] != 0) return false;

    queue<int> q;
    q.push(0);
    is_visited[0] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int next_target = after_room[curr];
        if (next_target != 0) {
            if (hang_over[next_target]) {
                is_visited[next_target] = true;
                q.push(next_target);
            }
            before_room[next_target] = 0;
        }

        for (int next : graph[curr]) {
            if (is_visited[next]) continue;

            if (before_room[next] != 0) {
                hang_over[next] = true;
                continue;
            }
            is_visited[next] = true;
            q.push(next);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!is_visited[i]) return false;
    }

    return true;
}