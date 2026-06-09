#include <vector>

using namespace std;

vector<int> parent_map;

int getBaseAmount(int x, int coin) {
    if (x < coin) return x;
    if (parent_map[x] == x) {
        parent_map[x] = x - coin;
    }
    return parent_map[x];
}

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    parent_map.resize(n + 1);

    for (int coin : money) {
        for (int i = 0; i <= n; i++) parent_map[i] = i;

        for (int i = coin; i <= n; i++) {
            int prev = getBaseAmount(i, coin);
            dp[i] = (dp[i] + dp[prev]) % 1000000007;
        }
    }

    return dp[n];
}