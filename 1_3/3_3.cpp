#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<set<int>> edges;
int discovered[301]; // 각 노드의 방문 순서 (0이면 미방문)
int low[301];        // 해당 노드에서 갈 수 있는 가장 빠른 방문 순서
bool is_articulation[301]; // 단절점 여부 체크
int timer = 0;       // 방문 순서를 매길 타이머

// cross: 현재 노드, is_root: 루트 노드 여부
void DFS(int cross, bool is_root) {
    discovered[cross] = low[cross] = ++timer; // 1. 방문 순서 기록
    int children = 0; // 루트 노드 판정을 위한 자식 수

    for (int next : edges[cross - 1]) {
        // 이미 방문한 노드라면 (역방향 간선)
        if (discovered[next]) {
            // 이미 가본 곳 중 가장 빠른 순서로 내 low를 갱신
            low[cross] = min(low[cross], discovered[next]);
            continue;
        }

        // 아직 방문 안 한 노드라면 (트리 간선)
        children++;
        DFS(next, false);

        // 자식의 탐색이 끝나고 돌아오면서 내 low를 갱신
        low[cross] = min(low[cross], low[next]);

        // 2. 단절점 판정 조건 (루트가 아닐 때)
        if (!is_root && low[next] >= discovered[cross]) {
            is_articulation[cross] = true;
        }
    }

    // 3. 루트 노드 판정: 자식이 2개 이상이면 단절점
    if (is_root && children >= 2) {
        is_articulation[cross] = true;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    edges.resize(N);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].insert(b);
        edges[b - 1].insert(a);
    }

    // 모든 노드를 돌며 DFS 실행 (끊겨있는 그래프 대비)
    for (int i = 1; i <= N; ++i) {
        if (!discovered[i]) DFS(i, true);
    }

    // 결과 출력
    vector<int> result;
    for (int i = 1; i <= N; ++i) {
        if (is_articulation[i]) result.push_back(i);
    }

    cout << result.size() << endl;
    for (int node : result) cout << node << "\n";

    return 0;
}