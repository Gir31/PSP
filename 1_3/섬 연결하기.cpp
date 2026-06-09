#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int findParent(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = findParent(parent, parent[x]);
    }
    return parent[x];
}

void unionSets(vector<int>& parent, int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int edges = 0;

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    sort(costs.begin(), costs.end(), compare);

    for (int i = 0; i < costs.size(); i++) {
        int u = costs[i][0];
        int v = costs[i][1];
        int cost = costs[i][2];

        if (findParent(parent, u) != findParent(parent, v)) {
            unionSets(parent, u, v);
            answer += cost;
            edges++;

            if (edges == n - 1) {
                break;
            }
        }
    }

    return answer;
}