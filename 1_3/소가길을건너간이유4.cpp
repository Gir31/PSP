#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int C, N;
    if (!(cin >> C >> N)) return 0;

    vector<int> chickens(C);
    for (int i = 0; i < C; i++) {
        cin >> chickens[i];
    }

    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    int cowIndex = 0;
    int matchCount = 0;

    for (int i = 0; i < C; i++) {
        int t = chickens[i];

        while (cowIndex < N && cows[cowIndex].first <= t) {
            pq.push(cows[cowIndex].second);
            cowIndex++;
        }

        while (!pq.empty() && pq.top() < t) {
            pq.pop();
        }

        if (!pq.empty()) {
            pq.pop();
            matchCount++;
        }
    }

    cout << matchCount;

    return 0;
}