#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct Node {
    int cost;
    int x;
    int y;

    bool operator>(const Node& other) const {
        return this->cost > other.cost;
    }
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();

    int start_x = 0, start_y = 0;
    int goal_x = 0, goal_y = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                start_x = i; start_y = j;
            }
            else if (board[i][j] == 'G') {
                goal_x = i; goal_y = j;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[start_x][start_y] = 0;
    pq.push({ 0, start_x, start_y });

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.cost > dist[curr.x][curr.y]) continue;

        if (curr.x == goal_x && curr.y == goal_y) {
            return curr.cost;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x;
            int ny = curr.y;

            while (true) {
                int next_x = nx + dx[i];
                int next_y = ny + dy[i];

                if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || board[next_x][next_y] == 'D') {
                    break;
                }
                nx = next_x;
                ny = next_y;
            }

            int next_cost = curr.cost + 1;
            if (next_cost < dist[nx][ny]) {
                dist[nx][ny] = next_cost;
                pq.push({ next_cost, nx, ny });
            }
        }
    }

    return -1;
}