#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(ability.begin(), ability.end());

    for (int i = 0; i < number; ++i)
    {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int sum = first + second;
        pq.push(sum); pq.push(sum);
    }

    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    return answer;
}