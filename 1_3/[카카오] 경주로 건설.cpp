#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct State {
    int cost;
    int x;
    int y;
    int dir;

    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int solution(vector<vector<int>> board) {
    int n = board.size();

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    const int INF = 1e9;

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));

    priority_queue<State, vector<State>, greater<State>> pq;

    pq.push({ 0, 0, 0, -1 });
    for (int i = 0; i < 4; i++) {
        dist[0][0][i] = 0;
    }

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        int cost = curr.cost;
        int x = curr.x;
        int y = curr.y;
        int dir = curr.dir;

        if (x == n - 1 && y == n - 1) {
            return cost;
        }

        if (dir != -1 && cost > dist[x][y][dir]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1) continue;

            int next_cost = 0;
            if (dir == -1) { 
                next_cost = cost + 100;
            }
            else if (dir == i) {
                next_cost = cost + 100;
            }
            else {
                next_cost = cost + 600;
            }

            if (next_cost < dist[nx][ny][i]) {
                dist[nx][ny][i] = next_cost;
                pq.push({ next_cost, nx, ny, i });
            }
        }
    }

    return 0;
}