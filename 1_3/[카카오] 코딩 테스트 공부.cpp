#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct State {
    int cost, alp, cop;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int solution(int alp, int cop, vector<vector<int>> problems) {

    int maxAlp = 0, maxCop = 0;
    for (auto& p : problems) {
        maxAlp = max(maxAlp, p[0]);
        maxCop = max(maxCop, p[1]);
    }

    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);

    const int INF = 1e9;
    vector<vector<int>> dist(maxAlp + 1, vector<int>(maxCop + 1, INF));
    dist[alp][cop] = 0;

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({ 0, alp, cop });

    while (!pq.empty())
    {
        State curr = pq.top(); pq.pop();

        int cost = curr.cost;
        int a = curr.alp;
        int c = curr.cop;

        if (cost > dist[a][c]) continue;
        if (a == maxAlp && c == maxCop) break;

        if (a + 1 <= maxAlp && dist[a + 1][c] > cost + 1)
        {
            dist[a + 1][c] = cost + 1;
            pq.push({ dist[a + 1][c], a + 1, c });
        }

        if (c + 1 <= maxCop && dist[a][c + 1] > cost + 1)
        {
            dist[a][c + 1] = cost + 1;
            pq.push({ dist[a][c + 1], a, c + 1 });
        }

        for (auto& p : problems)
        {
            if (a < p[0] || c < p[1]) continue;

            int na = min(a + p[2], maxAlp);
            int nc = min(c + p[3], maxCop);
            int next_cost = cost + p[4];

            if (dist[na][nc] > next_cost)
            {
                dist[na][nc] = next_cost;
                pq.push({ next_cost, na, nc });
            }
        }
    }

    return dist[maxAlp][maxCop];
}