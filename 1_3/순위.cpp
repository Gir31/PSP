#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

    for (const auto& res : results) {
        int win = res[0];
        int lose = res[1];
        graph[win][lose] = true;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (graph[i][j] || graph[j][i]) {
                count++;
            }
        }
        if (count == n - 1) {
            answer++;
        }
    }

    return answer;
}