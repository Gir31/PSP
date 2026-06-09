#include <vector>
#include <set>

using namespace std;

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

int solution(int n, vector<vector<int>> computers) {
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (computers[i][j] == 1) {
                unionSets(parent, i, j);
            }
        }
    }

    set<int> networks;
    for (int i = 0; i < n; i++) {
        networks.insert(findParent(parent, i));
    }

    return networks.size();
}