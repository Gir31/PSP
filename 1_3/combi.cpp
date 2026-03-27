#include <iostream>
#include <vector>

using namespace std;

// 파이썬의 comb(lst, n)와 동일한 구조
vector<vector<int>> comb(vector<int> lst, int n) {
    vector<vector<int>> ret;

    // 1. 예외 처리: 뽑으려는 개수가 리스트 크기보다 크면 빈 결과 반환
    if (n > lst.size()) {
        return ret;
    }

    // 2. 기저 사례: 1개만 뽑는 경우 (n == 1)
    if (n == 1) {
        for (int i : lst) {
            ret.push_back({ i });
        }
        return ret;
    }

    // 3. n > 1인 경우 재귀 호출
    // range(len(lst) - n + 1)와 동일한 반복 범위
    for (int i = 0; i <= (int)lst.size() - n; ++i) {
        // 파이썬의 lst[i+1:]를 모방: i+1번째부터 끝까지 새로운 벡터 생성
        vector<int> rest(lst.begin() + i + 1, lst.end());

        // 재귀 호출: 나머지 원소들 중 n-1개를 뽑음
        for (vector<int> temp : comb(rest, n - 1)) {
            // [lst[i]] + temp 연산 (현재 원소 + 재귀 결과 조합)
            vector<int> next_comb = { lst[i] };
            next_comb.insert(next_comb.end(), temp.begin(), temp.end());
            ret.push_back(next_comb);
        }
    }

    return ret;
}

int main() {
    vector<int> data = { 1, 2, 3, 4 };
    int n = 2;

    vector<vector<int>> results = comb(data, n);

    for (const auto& row : results) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}