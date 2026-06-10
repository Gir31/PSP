#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct GAS_STATION {
    int range;
    int gas;
};

bool compare(const GAS_STATION& a, const GAS_STATION& b) {
    return a.range < b.range;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<GAS_STATION> gs(N);
    for (int i = 0; i < N; ++i) {
        cin >> gs[i].range >> gs[i].gas;
    }
    sort(gs.begin(), gs.end(), compare);

    int destination, curr_gas;
    cin >> destination >> curr_gas;

    priority_queue<int> pq;
    long long current_range = curr_gas;
    int idx = 0;
    int answer = 0;

    while (current_range < destination) {
        while (idx < N && gs[idx].range <= current_range) {
            pq.push(gs[idx].gas);
            idx++;
        }

        if (pq.empty()) {
            answer = -1;
            break;
        }

        current_range += pq.top();
        pq.pop();
        answer++;
    }

    cout << answer << "\n";

    return 0;
}