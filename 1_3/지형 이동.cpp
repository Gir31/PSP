#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct Cell {
    int cost;
    int x;
    int y;

    bool operator>(const Cell& other) const {
        return this->cost > other.cost;
    }
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int solution(vector<vector<int>> land, int height) {
    int n = land.size();
    int answer = 0;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    dist[0][0] = 0;
    pq.push({ 0, 0, 0 });

    while (!pq.empty()) {
        Cell curr = pq.top();
        pq.pop();

        if (visited[curr.x][curr.y]) continue;
        visited[curr.x][curr.y] = true;

        answer += curr.cost;

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                int diff = abs(land[curr.x][curr.y] - land[nx][ny]);
                int next_cost = 0;

                if (diff > height) {
                    next_cost = diff;
                }
                else {
                    next_cost = 0;
                }

                if (next_cost < dist[nx][ny]) {
                    dist[nx][ny] = next_cost;
                    pq.push({ next_cost, nx, ny });
                }
            }
        }
    }

    return answer;
}