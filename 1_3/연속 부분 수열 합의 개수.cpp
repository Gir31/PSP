#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> unique_sums;
    int n = elements.size();

    for (int i = 0; i < n; i++) {
        elements.push_back(elements[i]);
    }

    for (int len = 1; len <= n; len++) {
        int current_sum = 0;

        for (int i = 0; i < len; i++) {
            current_sum += elements[i];
        }
        unique_sums.insert(current_sum);

        for (int i = 1; i < n; i++) {
            current_sum -= elements[i - 1];
            current_sum += elements[i + len - 1];
            unique_sums.insert(current_sum);
        }
    }

    return unique_sums.size();
}