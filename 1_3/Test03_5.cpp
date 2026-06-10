#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> counter(100001, 0);
    int max_length = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        counter[a[right]]++;

        while (counter[a[right]] > k) {
            counter[a[left]]--;
            left++;
        }

        max_length = max(max_length, right - left + 1);
    }

    cout << max_length;

    return 0;
}