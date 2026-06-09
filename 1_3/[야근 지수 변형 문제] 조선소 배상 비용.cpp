#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());

    for (int i = 0; i < n; ++i)
    {
        if (pq.empty()) break;
        int work = pq.top() - 1; pq.pop();
        if (work > 0) pq.push(work);
    }

    while (!pq.empty())
    {
        int work = pq.top(); pq.pop();
        answer += (work * work);
    }

    return answer;
}