#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) cin >> words[i];

    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
        });

    words.erase(unique(words.begin(), words.end()), words.end());

    for (const string& word : words) cout << word << '\n';

    return 0;
}